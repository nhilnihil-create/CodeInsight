#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353
#define Graph vector<vector<int>>

int main() {
    ll X, Y, A, B, C; cin >> X >> Y >> A >> B >> C;
    vector<ll> p(A), q(B), r(C);
    for (int i = 0; i < A; i++) {
        cin >> p.at(i);
    }
    for (int i = 0; i < B; i++) {
        cin >> q.at(i);
    }
    for (int i = 0; i < C; i++) {
        cin >> r.at(i);
    }
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    sort(r.begin(), r.end());
    ll psum = 0, qsum = 0;
    ll pk = A - X, qk = B - Y, rk = C - 1;
    for (int i = 0; i < C; i++) {
        ll P, Q, R = r.at(rk);
        if (pk < A) P = p.at(pk);
        else P = inf;
        if (qk < B) Q = q.at(qk);
        else Q = inf;
        ll low = min(P, Q);
        if (low == P && P < R && pk < A) {
            swap(p.at(pk), r.at(rk));
            pk++;
            rk--;
        }
        else if (low == Q && Q < R && qk < B) {
            swap(q.at(qk), r.at(rk));
            qk++;
            rk--;
        }
        if (rk < 0) break;
    }
    for (int i = A - 1; i >= A - X; i--) {
        psum += p.at(i);
    }
    for (int i = B - 1; i >= B - Y; i--) {
        qsum += q.at(i);
    }
    cout << psum + qsum << endl;
}