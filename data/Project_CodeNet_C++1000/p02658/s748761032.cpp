#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

const ll big=1e18;

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll ans=1;
    rep(i,n){
        cin>>a[i];
        if(a[i]==0){
            cout<<0<<endl;
            return 0;
        }
    }
    rep(i,n){
        if(ans>big/a[i]+1){
            cout<<-1<<endl;
            return 0;
        }
        ans*=a[i];
        if(ans>big){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
}