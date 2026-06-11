#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n,d;
  cin >> n >> d;
  ll ans=0;
  rep(i,n){
    ll x,y;
    cin >> x >> y;
    
    ll dist = x*x + y*y;
    if(dist <= d*d) ans++;
  }
  cout << ans << endl;
  
  return 0;
    

}
