#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
        int N, K;
        cin >> N >> K;
        ll s[N+1];
        ll se[N+1];
        rep(i,N) {
                int p;
                cin >> p;
                s[i] = (p+1);
        }
        se[0] = 0;
        rep(i,N) {
                se[i+1] = se[i] + s[i];
        }
        ll ans = 0;
        for (int i = 0; i <=N-K; i++) {
                ans = max(ans, se[i+K]-se[i]);
        }
        cout << setprecision(10) << (double)ans/2.0 << endl;

        return 0;
}