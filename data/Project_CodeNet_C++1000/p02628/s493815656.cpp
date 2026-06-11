#include<bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, k, a;
    cin >> n >> k;
    vll x;
    
    for(ll i=0; i<n; i++){
        cin >> a;
        x.push_back(a);
    }
    
    sort(x.begin(), x.end());
    ll ans = 0;
    for(ll i=0; i<k; i++){
        ans += x[i];
    }
    
    cout << ans << endl;
    return 0;
}