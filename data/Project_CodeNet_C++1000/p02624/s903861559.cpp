#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;

int main(){
    cin >> n;
    ll ans = 0;
    for(ll i=1; i<=n; i++){
        ans+=i*(n/i)*(n/i+1)/2;
    }
    cout << ans << endl;
}
