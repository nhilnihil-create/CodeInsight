#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    ll k;
    cin>>k;

    ll a=0;
    ll c=1;
    ll ans=1;
    rep(i,10000000){
        ll tmp=(7*c)%k;
        a=(a+tmp)%k;
        if(a%k==0){
            cout<<ans<<endl;
            return 0;
        }
        c=(c*10)%k;
        ans++;
    }

    cout<<-1<<endl;
}
