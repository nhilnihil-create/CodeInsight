#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int H, W, A, B; cin >> H >> W >> A >> B;

    REP(i, 0, H) {
        REP(j, 0, A) cout << ((i < B) ? 0 : 1);
        REP(j, A, W) cout << ((i < B) ? 1 : 0);
        cout << endl;
    }

    return 0;
}