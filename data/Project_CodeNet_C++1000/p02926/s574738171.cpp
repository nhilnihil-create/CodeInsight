#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
const ll INF = 999999999999999;
const ll MOD = 1000000007;
const ll MAX_N = 500010;
ll A, B, C, D, E, F, G, H, X, Y, Z, P, Q, M, N, T, R, K, W, L, ANS;
string S, S1, S2;
using p = pair<double, double>;

using p = pair<double, double>;
vector<p> V;

double dot(p a, p b) { return a.first * b.first + a.second * b.second; }

double norm(p a) { return sqrt(a.first * a.first + a.second * a.second); }

p operator+(p a, p b) { return p(a.first + b.first, a.second + b.second); }

p operator-(p a, p b) { return p(a.first - b.first, a.second - b.second); }
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i, N) {
        cin >> X >> Y;
        if(X != 0 || Y != 0)
            V.push_back({X, Y});
    }

    N = V.size();

    sort(all(V), [](auto const &A1, auto const &A2) { return atan2(A1.second, A1.first) > atan2(A2.se, A2.fi); });

    p SUM = {0, 0};
    rep(i, N) { SUM = SUM + V[i]; }

    vector<p> RUISEKI;
    p NOW = {0, 0};
    RUISEKI.push_back(NOW);
    rep(i, N) {
        NOW = NOW + V[i];
        RUISEKI.push_back(NOW);
    }

    double ANS = 0;

    rep(i, N) {
        rep(j, i + 1) {
            ANS = max({norm(RUISEKI[i + 1] - RUISEKI[j]), norm(SUM - (RUISEKI[i + 1] - RUISEKI[j])), ANS});
        }
    }

    cout << setprecision(15) << ANS << endl;
}