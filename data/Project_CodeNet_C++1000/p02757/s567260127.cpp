#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

int main() {

    int N, P;
    cin >> N >> P;
    string S;
    cin >> S;

    vector<int> A(N), M(N + 1, 0);

    rep(i,N) A[i] = S[N - 1 - i] - '0';

    ll ans = 0;
    if (P == 2 || P == 5) {
        rep(i,N) if (A[i] % P == 0) ans += N - i;
        cout << ans << endl;
        return 0;
    }

    ll ten = 1;
    rep(i,N) {
        M[i + 1] = M[i] + ten * A[i];
        M[i + 1] %= P;
        ten *= 10;
        ten %= P;
    }
    vector<int> modCount(P, 0);
    rep(i,N + 1) {
        ans += modCount[M[i]];
        modCount[M[i]]++;
    }

    cout << ans << endl;
    
    return 0;
}