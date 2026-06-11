#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
using P=pair<int,int>;
typedef unsigned long long ull;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const ll INF=1e18;
const ll MOD=998244353;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int n;
int d[100010];
ll c[100010];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);  
  
  cin >> n;  
  rep(i,n){
    cin >> d[i];
    c[d[i]]++;
  }
  if(d[0]!=0){
    cout << 0 << endl;
    return 0;
  }
  
  ll ans=1ll;
  for(int i=1;i<n;i++){
    ans=ans*c[d[i]-1]%MOD;
  }
  cout << ans << endl;
}
