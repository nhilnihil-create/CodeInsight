#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;

/* --------------------------------------------------- */

int main() {
    ll x, k, d;
    cin >> x >> k >> d;

    ll a = ceil((double)abs(x) / d);

    a = min(a, k);
    if(x >= 0) {
        x -= a * d;
        k -= a;
        if(k % 2 == 1) x += d;
    } else if(x < 0) {
        x += a * d;
        k -= a;
        if(k % 2 == 1) x -= d;
    }
    cout << abs(x) << endl;
    return 0;
}