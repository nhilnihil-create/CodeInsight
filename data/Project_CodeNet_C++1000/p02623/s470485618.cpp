#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int main(){
    ll n,m;
    ll k;
    vector<ll> a,b;
    cin >> n >> m >> k;
    a.resize(n+10);
    b.resize(m+10);
    vector<ll> sum_a(n+10,0);
    vector<ll> sum_b(m+10,0);
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum_a[i+1] = sum_a[i]+a[i];
    }
    for(int j=0; j<m; j++){
        cin >> b[j];
        sum_b[j+1] = sum_b[j]+b[j];
    } 
    ll ans=0;
    ll j=m;
    for(ll i=0; i<=n; i++){
        if(sum_a[i]>k) break;
        ll temp_max=k-sum_a[i];
        while(sum_b[j]>temp_max) j--;
        ans = max(ans,i+j);
    }
    cout << ans << "\n";
    return 0;
}
