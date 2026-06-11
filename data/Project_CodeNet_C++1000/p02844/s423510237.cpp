#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

// https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d

int keta = 3;

string fill0(int num, int keta) {
	ios::fmtflags curret_flag = cout.flags();

	ostringstream ss;
	ss << setw(keta) << setfill('0') << num;
	string s(ss.str());
	cout.flags(curret_flag);
  return s;
}

bool f(string &s, string &digit) {
  int cur = 0;
  for(char c : s) {
    if(c == digit[cur]) {
      cur++;
    }
    if(cur >= digit.size()) {
      return true;
    }
  }
  return false;
}

int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  int ans = 0;
  for(int i=0;i<1000;i++) {
    string digit = fill0(i, keta);
    if(f(s, digit)) ans++;
  }

  cout << ans << endl;
  return 0;
}
