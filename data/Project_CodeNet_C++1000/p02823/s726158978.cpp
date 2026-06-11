#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N, A, B;
int main() {
    cin >> N >> A >> B;
    ll dist = abs(A - B) - 1;
    ll ans = INF;
    if (dist % 2 == 1) {
        ans = (dist + 1) / 2;
    } else {
        // A < B 

        ll tmp = 0;
        // A が1にぶつかってから向かう
        // ll base = A - 1; // A が壁にぶつかるまで
        ll base = A; // A が壁にぶつかるまで
        tmp = (dist + base * 2) / 2;
        // cout << tmp << endl;
        ans = min(ans, tmp);

        // B がNにぶつかってから向かう 
        base = N - B + 1;
        // tmp = base + ((N - (A + base)) / 2);
        tmp = (dist + base * 2) / 2;
        // cout << tmp << endl;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}