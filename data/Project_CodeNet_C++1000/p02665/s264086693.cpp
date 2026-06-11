#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n;
ll a[MN];
ll ps[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n+1) cin >> a[i];
    RFOR(i, n, 0) ps[i] = ps[i+1]+a[i];
    ll sm = 0;
    ll amt = 1;
    F0R(i, n+1){
        sm += amt;
        amt -= a[i];
        amt *= 2;
        amt = min(amt, ps[i+1]);
        if(amt < 0){
            cout << "-1\n";
            return 0;
        }
    }
    cout << sm << "\n";

    return 0;
}
