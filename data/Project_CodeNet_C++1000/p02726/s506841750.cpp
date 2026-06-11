#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")




int main() {

    ll n,x,y; cin >> n >> x >> y;
    ll d;
    vector<ll> v(n,0);

    for(ll i = 1; i <= n-1; i ++){
        for(ll j = i+1; j <= n; j ++){
            d = j-i;
            if(x >= i && j >= y){
                d -= (y-x-1);
            }else{
                ll d1 = abs(i-x);
                ll d2 = abs(i-y);
                if(d1 < d2){
                    d = min(d, d1 + 1 + abs(y-j));
                }else{
                    d = min(d, d1 + 1 + abs(x-j));
                }
            }
            v[d] ++;

        }
    }

    for(ll i = 1; i <= n-1; i ++){
        cout << v[i] << endl;
    }
    return 0;
}
