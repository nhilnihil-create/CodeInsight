#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;


int main() {
  ll k,q;
  cin >> k >> q;
  vector<ll> d(k);
  rep(i,k) cin >> d[i];
  rep(ii,q){
      ll n,x,m;
      cin >> n >> x >> m;
      n--;
      x=x%m;
      ll y=0;
      rep(i,k){
          y+=d[i]%m;
          if (d[i]%m==0) y+=m;
      }
      ll ans=0;
      ans=k*(n/k);
      ans-=(x+y*(n/k))/m;
      x=(x+y*(n/k))%m;
      rep(i,n%k){
          if (x+d[i]%m < m && d[i]%m!=0) ans++;
          x=(x+d[i]%m)%m; 
      }
      cout << ans << endl;
  }
}
