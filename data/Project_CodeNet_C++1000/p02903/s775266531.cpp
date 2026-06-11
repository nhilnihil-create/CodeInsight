#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main() {

    ll h,w,a,b; cin >> h >> w >> a >> b;
    rep(i,h){
        rep(j,w){
            if(j < a && i < b) cout << 1;
            else if(j < a && i >= b) cout << 0;
            else if(j >= a && i >= b) cout << 1;
            else if(j >= a && i < b) cout << 0;
        }
        cout << endl;
    }

}
