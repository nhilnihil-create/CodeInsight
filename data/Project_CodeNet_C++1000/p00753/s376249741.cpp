#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) REP((i), 0, (n))
#define REP(i, a, n) for(int i=(a); i<(n); i++)

bool a[300000];

int main() {
    while(1) {
        int n; cin >> n;
        if(n == 0) break;
        
        // eratosthenes
        int N = 2*n+1;
        memset(a, true, N);
        REP(i, 2, sqrt(N)) {
            if(a[i]) {
                for(int j=0; i*(j+2)<N; j++) {
                    a[i*(j+2)] = false;
                }
            }
        }
        
        int ans = 0;
        rep(i, N) {
            if(i > n) if(a[i]) ans++;
        }
        cout << ans << endl;
    }
}
