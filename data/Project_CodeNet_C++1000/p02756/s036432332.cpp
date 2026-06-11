#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll x = 1e9 + 7; 
const int INF = 1001001001;


int main() {
  string s;
  int q;
  cin >> s >> q;
  int flag = 1;
  string front = "", back = "";
  rep(i,q) {
    int t;
    cin >> t;
    if (t == 1) flag *= -1;
    if (t == 2) {
      int f;
      char sq;
      cin >> f >> sq;
      if (f*flag == 1 || f*flag == -2) front.push_back(sq);
      if (f*flag == 2 || f*flag == -1) back.push_back(sq);
    }
  }
  string ans;
  if (flag == -1) {
    reverse(s.begin(), s.end());
    reverse(back.begin(), back.end());
    ans = back + s + front;
  }
  else {
    reverse(front.begin(), front.end());
    ans = front + s + back;
  }
  cout << ans << endl;
  return 0;
}