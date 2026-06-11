#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define FOR(i,a,b)  for(ll i=a;(i)<(b);++(i))
#define RFOR(i,a,b) for(ll i=a;(i)>=(b);--(i))
#define REP(i,n)    FOR(i,0,n)
#define RREP(i,n)   RFOR(i,n,0)
#define ALL(v)      v.begin(), v.end()
#define UNIQ(v)     sort(ALL(v)); v.erase(unique(ALL(v)), v.end())
#define BIT(n)      (1LL<<(n))
#define DEBUG(a)    cerr << #a << " = " << a << endl

const double PI = acos(-1);
const int inf = 1001001001;
const int mod = (int)1e9+7;
//const ll inf = 1e15;
//const ll mod = 1e9+7;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int main() {
    int N;
    string S;
    cin >> N >> S;

    vector<int> a(N);
    REP(i, N) {
        if (S[i] == 'R') a[i] = 0;
        if (S[i] == 'G') a[i] = 1;
        if (S[i] == 'B') a[i] = 2;
    }
    vector<ll> cnt(3);
    REP(i,N) cnt[a[i]]++;

    ll ans = 1;
    REP(i, 3) ans *= cnt[i];
    REP (i, N) {
        FOR (j, i, N) {
            int k = 2 * j - i;
            if (k < N) {
                if (a[i] == a[j]) continue;
                if (a[j] == a[k]) continue;
                if (a[i] == a[k]) continue;
                ans--;
            }
        }
    }

    cout << ans << endl;
}
