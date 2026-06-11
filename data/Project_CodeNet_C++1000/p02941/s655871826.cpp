#include <bits/stdc++.h>
using namespace std;

struct Benri {
    Benri() {
        std::cin.tie(0); ios::sync_with_stdio(false);
        cout << fixed << setprecision(12);
    }
} benri;
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vll = vector<long long>;
using pll = pair<ll, ll>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
const int INF = 1 << 28;


int main() {
    int N; cin >> N;
    vll A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    priority_queue<pair<ll, int>> pq;
    rep(i, N) pq.push(mp(B[i], i));

    bool can = true;
    ll ans = 0;

    while (!pq.empty()) {
        ll C = pq.top().F;
        int i = pq.top().S;
        pq.pop();
        ll X = B[(i - 1 + N) % N] + B[(i + 1) % N];

        if (C < A[i]) {
            can = false;
            break;
        }
        else if (C == A[i]) {
            continue;
        }
        else if (C > A[i] && C < X + A[i]) {
            can = false;
            break;
        }
        else {
            ll tmp = (C - A[i]) / X;
            C = C - X * tmp;
            B[i] = C;
            ans += tmp;
            pq.push(mp(C, i));
        }
    }

    cout << (can ? ans : -1) << endl;

}


