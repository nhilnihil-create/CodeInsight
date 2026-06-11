#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> P;
typedef pair<ll, pair<ll, ll> > P3;

const ll MOD = ll(1e9 + 7);
const ll LLINF = LLONG_MAX;
const int IINF = INT_MAX;
const int MAX_N = int(1e5) + 5;
const double EPS = 1e-8;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i < n; i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n),dp(n+1,IINF);
    REP(i,n)cin >> a[i];
    REP(i,n){
        *lower_bound(dp.begin(),dp.end(),a[i]) = a[i];
    }
    cout << lower_bound(dp.begin(),dp.end(),IINF)-dp.begin() << endl;
    return 0;
}

