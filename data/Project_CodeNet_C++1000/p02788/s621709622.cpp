#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, D, A;
    cin >> N >> D >> A;
    vector<ll> X(N), H(N);
    vector<pii> XH(N);
    REP(i, N) {
        cin >> X[i] >> H[i];
        XH[i] = pii(X[i], H[i]);
    }
    sort(all(XH));
    REP(i, N) {
        tie(X[i], H[i]) = XH[i];
    }
        
    ll result = 0;
    ll atack = 0;
    vector<ll> acc(N + 1, 0);

    REP(i, N) {
        atack += acc[i];
        int life = max(H[i] - atack, 0ll);
        int cnt = (life + A - 1) / A;
        int j = distance(X.begin(), upper_bound(all(X), X[i] + 2 * D));
        acc[i] += A * cnt;
        acc[j] -= A * cnt;
        result += cnt;
        atack += A * cnt;
    }

    cout << result << endl;

    return 0;
}
