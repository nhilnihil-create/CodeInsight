#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define pb push_back

const int N = 1e7 + 10;
int spf[N];
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i) {
            if(spf[j] == 0) {
                spf[j] = i;
            }
        }
    }
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int res = 1; 
        int p = i;
        int sp = spf[i];
        while (p > 1) {
            int ct = 0;
            while (p % sp == 0) {
                p /= sp;
                ct ++;
            }
            sp = spf[p];
            res *= (ct + 1);
        }
        ans += i * res;
    }
    cout << ans << endl;

    return 0;
}

