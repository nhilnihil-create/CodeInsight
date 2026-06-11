#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;

    int count[3] = {}; ll ans = 1;
    REP(i, 0, N) {
        int a; cin >> a;
        int cnt = 0;
        REP(j, 0, 3) if (count[j] == a) cnt++;
        REP(j, 0, 3) {
            if(count[j] == a) {
                count[j]++;
                break;
            }
        }
        ans = (ans * cnt) % MOD;
    }
    cout << ans << endl;
    return 0;
}