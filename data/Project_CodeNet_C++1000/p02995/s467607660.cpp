#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

ll a, b, c, d;

ll count(ll x){
    return x - (x/c + x/d - x/(c*d/__gcd(c,d)));
}

int main(){
    cin >> a >> b >> c >> d;
    cout << count(b) - count(a-1) << endl;
    return 0;
}
