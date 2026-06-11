#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,b) for (ll i=a;i<=ll(b);i++)
using namespace std;
ll ctoi(const char c){if('0'<=c&&c<='9') return (c-'0');return -1;}
#define ALL(x) begin(x),end(x)
  
int main(){
  ll x;
  cin >> x;
  if(400<=x&&x<=599) cout << "8" << endl;
  if(600<=x&&x<=799) cout << "7" << endl;
  if(800<=x&&x<=999) cout << "6" << endl;
  if(1000<=x&&x<=1199) cout << "5" << endl;
  if(1200<=x&&x<=1399) cout << "4" << endl;
  if(1400<=x&&x<=1599) cout << "3" << endl;
  if(1600<=x&&x<=1799) cout << "2" << endl;
  if(1800<=x&&x<=1999) cout << "1" << endl;
} 