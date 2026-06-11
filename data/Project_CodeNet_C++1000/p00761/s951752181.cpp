#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

int main() {
  int a, l;
  while (true) {
    cin >> a >> l;
    if (a == 0 && l == 0) break;
    map<int, int> s;
    s[a] = 0;
    while (true) {
      vector<int> v;
      rep (i, l) {
	v.push_back(a % 10);
	a /= 10;
      }
      sort(v.begin(), v.end());
      int mx = 0, mn = 0;
      rep (i, l) {
	mx *= 10;
	mn *= 10;
	mx += v[l - i - 1];
	mn += v[i];
      }
      a = mx - mn;
      //cout << a << " " << s.size() << endl;
      int sz = s.size();
      if (s.count(a) > 0) {
	cout << s[a] << " " << a << " " << sz - s[a] << endl;
	break;
      }
      s[a] = sz;
    }
  }
  return 0;
}