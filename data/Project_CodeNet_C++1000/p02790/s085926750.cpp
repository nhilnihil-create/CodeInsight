#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define xrep(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define vl vector<long long>
#define vs vector<string>

int main() {
    ll a,b; cin >> a >> b;

    ll A = a,B = b;
    rep(i,b-1){
        A *= 10;
        A += a;
    }
    rep(i,a-1){
        B *= 10;
        B += b;
    }

    if(a<b) cout << A << endl;
    else cout << B << endl; 

}