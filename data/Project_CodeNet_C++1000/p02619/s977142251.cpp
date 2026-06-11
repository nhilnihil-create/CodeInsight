#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007
#define MOD2 998244353
#define INF MOD
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

int last[400][30];
Int v[400];

int main() {
    int D;
    cin >> D;
    int c[30];
    Int s[D+10][30];
    Int t[D+10];
    map<int, int> last;
    for (int i = 1; i <= 26; i++) {
        cin >> c[i];
    }
    for (int d = 1; d <= D; d++) {
        for (int i = 1; i <= 26; i++) {
            cin >> s[d][i];
        }
    }
    for (int d = 1; d <= D; d++) {
        cin >> t[d];
    }
    Int total = 0;
    for (int d = 1; d <= D; d++) {
        last[t[d]] = d;
        total += s[d][t[d]];
        for (int i = 1; i <= 26; i++) {
            total -= c[i] * (d - last[i]);
        }
        v[d] = total;
    }
    for (int d = 1; d <= D; d++) {
        cout << v[d] << endl;
    }
}