#include <bits/stdc++.h>

using namespace std;

template<class Func, class Callback, class T>
void recurse(int from, int to, Func f, Callback cb,
             int& i, T& p, T q) {
	if (p == q) return;
	if (from == to) {
		cb(i, to, p);
		i = to; p = q;
	} else {
		int mid = (from + to) / 2;
		recurse(from, mid, f, cb, i, p, f(mid));
		recurse(mid + 1, to, f, cb, i, p, q);
	}
}
template<class Func, class Callback>
void ConstantIntervals(int from, int to, Func f, Callback cb) {
	if (to <= from) return;
	int i = from; auto p = f(i), q = f(to - 1);
	recurse(from, to - 1, f, cb, i, p, q);
	cb(i, to, q);
}

int main() {
  int n; cin >> n;
  map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x; cnt[x] += 1;
  }
  vector<int> v;
  for (auto p : cnt)
    v.push_back(p.second);
  sort(v.rbegin(), v.rend());

  vector<int> buff;
  auto eval = [&](int k) {
    int rem = n;
    for (auto x : v) {
      if (x <= rem / k)
        return rem / k;
      rem -= x;
      k -= 1;
    }
    return 0;
  };

  vector<int> ans(n);
  ConstantIntervals(1, n + 1, eval, [&](int b, int e, int x) {
    for (int i = b; i < e; ++i)
      ans[i - 1] = x;
  });
  
  for (int i = 0; i < n; ++i)
    cout << ans[i] << '\n';

  return 0;
}
