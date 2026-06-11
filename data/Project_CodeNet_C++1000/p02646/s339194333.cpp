#include <bits/stdc++.h>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
typedef long long ll;
typedef long double ld;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    ll a, v, b, w, t;

    cin >> a >> v >> b >> w >> t;

    if(v<=w) cout << "NO" << endl;

    else{
        ld d;
        d = (ld)abs(a-b)/(v-w);
        if(d<=t) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}