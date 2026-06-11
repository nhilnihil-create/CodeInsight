#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e10;
int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for(ll i=0; i<n; ++i){
        cin >> a[i];
    }
    ll r = INF, l = 0;
    ll res = 0;
    for(ll j=0; j<100; ++j){
        if(r-l<=1){break;}
        ll mid = (r+l)/2;
        
        ll sum = 0;
        for(ll i=0; i<n; ++i){
            sum += (a[i]-1)/mid;
        }
        
        if(sum>k){l = mid;}
        else{r = mid;}
    
    }
    
    cout << r << endl;
    return 0;
}