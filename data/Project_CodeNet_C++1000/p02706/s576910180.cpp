#include<bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, k, a;
    cin >> k >> n;
    vll x;
    
    for(ll i=0; i<n; i++){
        cin >> a;
        x.push_back(a);
    }
    ll ans = 0;
    for(ll i=0; i<n; i++){
        ans += x[i];
    }
    
    if(k < ans){
        cout << -1 << endl;
    }
    else{
        cout << k - ans << endl;
    }
    return 0;
}