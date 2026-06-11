#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;


int main(){
    ll n;
    cin >> n;
    ll mod=1e9+7;
    ll a[n];
    for(ll i=0;i<n;i++) cin >> a[i];
    vector<ll> x(n,0);
    vector<ll> y(n,0);
    vector<ll> z(n,0);
    for(ll i=0;i<n-1;i++){
        if(x[i]==a[i]){
            x[i+1]=x[i]+1;
            y[i+1]=y[i];
            z[i+1]=z[i];
        }
        else if(y[i]==a[i]){
            x[i+1]=x[i];
            y[i+1]=y[i]+1;
            z[i+1]=z[i];
        }
        else if(z[i]==a[i]){
            x[i+1]=x[i];
            y[i+1]=y[i];
            z[i+1]=z[i]+1;
        }
    }
    ll res=1;
    for(ll i=0;i<n;i++){
        ll count=0;
        if(x[i]==a[i]) count++;
        if(y[i]==a[i]) count++;
        if(z[i]==a[i]) count++;
        res*=count;
        res%=mod;
    }
    cout << res << endl;
    return 0;
}  
