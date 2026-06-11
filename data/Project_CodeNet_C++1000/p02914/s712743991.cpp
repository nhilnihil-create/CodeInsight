#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, int> ri3;
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
#define SZ(x) (int)(x).size()
#define ALL(x) begin(x), end(x) 
#define REP(i, n) for (int i = 0; i < n; ++i) 
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    ll A[N], xA = 0;
    FOR(i,0,N-1){
        cin >> A[i];
        xA ^= A[i];
    }

    FOR(i,0,N-1){
        A[i] &= ~xA;
    }

    ll ans = 0;
    for (int r = 0, c = 60; r < N && c >= 0; --c) if ((xA&(1LL<<c)) == 0) {
        int p = -1;
        FOR(i,r,N-1) if (A[i]&(1LL<<c)) {
            p = i;
            break;
        }
        if (p == -1) continue;
        swap(A[r], A[p]);
        FOR(i,r+1,N-1) if (A[i]&(1LL<<c)) A[i] ^= A[r];

        if ((ans&(1LL<<c)) == 0) ans ^= A[r];
        ++r;
    }

    cout << ((ans<<1) + xA);
}

