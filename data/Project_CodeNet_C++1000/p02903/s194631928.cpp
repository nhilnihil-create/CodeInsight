#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int H, W, A, B;
    cin >> H >> W >> A >> B;
    REP(i, H) {
        string s = "";
        if (i < B) {
            REP(j, A) s += '0';
            REP(j, W-A) s += '1';
        } else {
            REP(j, A) s += '1';
            REP(j, W-A) s += '0';
        }
        cout << s << '\n';
    }
}
