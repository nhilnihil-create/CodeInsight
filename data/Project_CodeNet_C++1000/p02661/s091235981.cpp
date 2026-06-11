#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define ALL(v) (v).begin(),(v).end()
#define REP(i, x, n) for(ll (i)=(x); (i)<(n); (i)++)
#define RREP(i, x, n) for(ll (i)=(n)-1; (i)>=x; (i)--)
#define FOR(i, n) for(ll (i)=0; (i)<(n); (i)++)
#define RFOR(i, n) for(ll (i)=(n)-1; (i)>=0; (i)--)

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        FOR(i, n) cin >> a[i] >> b[i];
        sort(ALL(a)); sort(ALL(b));
        if (n & 1) cout << b[n / 2] - a[n / 2] + 1 << endl;
        else cout << (b[n / 2] + b[n / 2 - 1]) - (a[n / 2] + a[n / 2 - 1]) + 1 << endl;

        return 0;
}