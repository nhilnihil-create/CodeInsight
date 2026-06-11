#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int N, K; cin >> N >> K;
    int ans = 0;
    REP(i, 0, N) {
        int a; cin >> a;
        if (a >= K) ans++;
    }
    cout << ans << endl;
    return 0;
}