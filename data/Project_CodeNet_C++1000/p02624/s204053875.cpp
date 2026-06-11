#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    ll n;
    cin>>n;
    ll ans=0;

    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=n;j+=i){
            ans+=j;
        }
    }

    cout<<ans<<endl;
}