#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int m;
    cin>>m;
    ll cnt=0,sum=0;
    rep(i,m){
        ll d,c;
        cin>>d>>c;
        cnt+=c;
        sum+=d*c;
    }
    ll ans=cnt-1+((sum-1)/9);

    cout<<ans<<endl;
}
