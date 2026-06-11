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

    ll ans=n/10;
    n/=10;

    ll p5=5;
    while(p5<=n){
        ans+=n/p5;
        p5*=5;
    }

    cout<<ans<<endl;
}
