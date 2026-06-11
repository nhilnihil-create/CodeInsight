#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
typedef pair<int,int> P;
const int INF=1e9;
int main(){
    ll ans=0;
    ll n;
    cin>>n;
    vector<ll> k(n+5);
    for(ll i=1;i<=n;i++){
        ll j=i;
        while(j<=n){
            k[j]++;
            j+=i;
        }
    }
    for(ll i=1;i<=n;i++){
        ans+=i*k[i];
    }
    cout<<ans;
}