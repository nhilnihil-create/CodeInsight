#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    ll goukei=0;
    for(ll i=0; i<n; i++){
         cin >> a[i];
         goukei += a[i];
}
    ll zettaiti = goukei;
    ll totyu=0;
    for(ll i=0; i<n; i++){
        totyu += a[i];
    zettaiti = min(zettaiti,abs(totyu-(goukei - totyu)));
    }
    cout << zettaiti << endl;
}