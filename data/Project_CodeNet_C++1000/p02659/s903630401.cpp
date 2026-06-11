#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll a; cin >> a;
  string b; cin >> b;
  ll ans = 0;
  ans += a * (b[0]-'0')*100;
  ans += a * (b[2]-'0')*10;
  ans += a * (b[3]-'0');
  cout << ans/100;
  cout << "\n";
  return 0;
}
