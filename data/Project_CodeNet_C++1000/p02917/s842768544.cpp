#include<bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
using namespace std;

int main(){
    ios_base::sync_with_stdio(true);
    cin.tie(NULL);
    ll n, a;
    cin >> n;
    vll x;
    for(ll i=0; i<n-1; i++){
        cin >> a;
        x.push_back(a);
    }
    ll ans = x[0] + x[n-2];
    for(ll i=1; i<n-1; i++){
        ans += min(x[i], x[i-1]);
    }
    cout << ans << endl;
    return 0;
}