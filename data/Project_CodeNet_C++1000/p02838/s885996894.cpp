#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const ll p = 1e9+7;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a.at(i);

    vector<ll> d(61);
    rep(i,n){
        for(int j=0;j<=60;j++){
            if(((ll)1<<j) & a.at(i)) d.at(j)++;
        }
    }

    ll tot = 0;
    rep(i,d.size()){
        ll x = (d.at(i) * (n-d.at(i))) % p;
        ll y = ((ll)1<<(ll)i) % p;
        // cout << i << " " << x << " * " << y << endl;
        tot = (tot + (x * y) % p) % p;
    }
    cout << tot << endl;
    return 0;
}