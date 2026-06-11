#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    ll l,r;
    cin>>l>>r;

    ll ans=2020;
    for(ll i=l;i<=min(r,l+3000);i++){
        for(ll j=i+1;j<=min(r,l+3000);j++){
            ans=min(ans,(i*j)%2019);
        }
    }

    cout<<ans<<endl;
}
