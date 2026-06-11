#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<(x)<<endl
#define fix cout<<fixed<<setprecision(20);
const int maxn=(int)1e6+5;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n;cin>>n;
    if(n==2){cout<<1<<endl;return 0;}
    ll ans=0;
    for(ll  i=1;i*i<n;i++){
        if((n-1)%i==0){ans+=2;if((n-1)/i==i)ans--;}
    }
    ans--;
    debug(ans);
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            ll x=n;while(x%i==0)x/=i;
            if((x-1)%i==0)ans++;
            ll ii=i;i=n/i;if(ii==i)continue;
             x=n;while(x%i==0)x/=i;
            if((x-1)%i==0)ans++;
            i=ii;
        }
    }
    ans++;
    cout<<ans<<endl;
}
