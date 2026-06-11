#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

template <typename T> inline void print(T val) { cout << val << '\n'; }

template <typename Iterator> inline void print(Iterator begin, Iterator end) {
  for (auto it = begin; it != end; it = next(it)) {
    cout << *it << ' ';
  }
  cout << '\n';
}

template <class T> inline T square(T x) {
  T result;
  result = x * x;
  return result;
};

#ifdef LOCAL
#define DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) 0
#endif

const int MOD = 1e9 + 7;
const int INF = 1e9 + 5;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  auto start = chrono::steady_clock::now();
#endif

int s,w;
  cin >> s>>w;

if(w >=s){
	print("unsafe");
}else{
	print("safe");
}

#ifdef LOCAL
  auto end = chrono::steady_clock::now();
  auto diff = end - start;

  cout << "Duration: " << chrono::duration<double, milli>(diff).count() << " ms"
       << '\n';
#endif

  return 0;
}
