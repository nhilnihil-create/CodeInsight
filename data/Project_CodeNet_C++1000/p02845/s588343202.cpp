#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n;
    cin>>n;
    vector<ll> b(n+1,0);
    b[0]=3;

    ll ans=1;
    rep(i,n){
        ll a;
        cin>>a;
        ans=(ans*b[a])%MOD;
        b[a]--;
        b[a+1]++;
    }
    cout<<ans<<endl;

}
