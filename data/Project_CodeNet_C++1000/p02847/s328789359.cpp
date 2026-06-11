#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int MOD=1000000007;

int main() {
  string s;
  cin >> s;
  int ans;
  if(s=="SUN") ans=7;
  if(s=="MON") ans=6;
  if(s=="TUE") ans=5;
  if(s=="WED") ans=4;
  if(s=="THU") ans=3;
  if(s=="FRI") ans=2;
  if(s=="SAT") ans=1;
  cout << ans << endl;
}
