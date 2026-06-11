#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);++i)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
// int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  ll n;
  cin >> n;
  ll m;
  cin >> m;
  vector<ll>b(n);
  ll bi=1;
  rep(i,n){
    cin >> b[i];
    b[i]/=2;
    bi=lcm(bi,b[i]);
  }
  bool ok = true;
  ll cnt=0;
  rep(i,n){
    ll num=0;
    while(b[i]%2==0){
      num++;
      b[i]/=2;
    }
    if(i==0){
      cnt=num;
    }
    else{
      if(cnt!=num)ok=false;
    }
  }
  if(ok) cout << (m/bi+1)/2 << endl;
  else cout << 0 << endl;
  return 0;
}
