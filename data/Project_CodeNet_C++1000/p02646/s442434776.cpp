#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int IINF = INT_MAX;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;


int main() {
    ll a, v, b, w, t; cin >> a >> v >> b >> w >> t;
    if(v <= w){
        cout << "NO" << endl;
        return 0;
    }

    if(abs(a - b) <= (v - w) * t){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
