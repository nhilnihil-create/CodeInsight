#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
const int MAX_N = 1.0e5 + 100;
int A[MAX_N];
const int MOD = 1.0e9 + 7;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    int color[3];
    memset(color, 0, sizeof(color));

    ll ans = 1;
    for (int i = 0; i < N; i++) {
        ll cnt = 0;
        bool f = false;
        for (int j = 0; j < 3; j++) {
            if (A[i] == color[j]) {
                if (!f) {
                    f = true;
                    color[j]++;
                }
                cnt++;    
            }
        }
        ans = (ans * cnt) % MOD;
    }

    cout << ans << endl;    
    
    return 0;
}
