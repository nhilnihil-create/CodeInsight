#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    ll n;
    cin>>n;

    if(n%2==1){
        cout<<0<<endl;
        return 0;
    }

    n/=2;
    ll ans=0;
    for(ll i=5;i<=n;i*=5){
        ans+=n/i;
    }

    cout<<ans<<endl;
}
