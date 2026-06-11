#include <fstream>
#include <iostream>

// BE CAREFUL WITH HASH TABLE & UNORDERED MAP
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define MOD 998244353
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = (b-1); i >= (a); i--)
#define RF0(i,b) RFO(i,0,b)
#define ll long long
#define pll pair<ll,ll>
#define add(a,b) ((int) (((lli) (a) + (b))%MOD))
#define mul(a,b) ((int) (((lli) (a) * (b))%MOD))
#define PB emplace_back
#define F first
#define S second

// ifstream cin ("cinput.in");
// ofstream cout ("coutput.out");

ll A1, A2, B1, B2, T1, T2;

// Helper Functions

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    pll A = make_pair(T1*A1+T2*A2, T1*A1);
    pll B = make_pair(T1*B1+T2*B2, T1*B1);
    ll diff = max(A,B).F - min(A,B).F;
    if (!diff) cout << "infinity\n";
    else {
        ll ans = 0;
        if (min(A,B).S > max(A,B).S) {
            ans++;
            ll diff2 = min(A,B).S - max(A,B).S;
            ans += 2ll * (diff2/diff);
            if (!(diff2%diff)) ans--;
        }
        cout << ans << '\n';
    }
}