#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
        int N, K;
        cin >> N >> K;
        double se[N+1];
        double sum = 0;
        rep(i,N) {
                int p;
                cin >> p;
                se[i] = sum;
                sum += (p+1)/2.;
        }
        se[N] = sum;
        double ans = 0;
        for (int i = K; i <= N; i++) {
                ans = max(ans, se[i]-se[i-K]);
        }
        cout << setprecision(10) << ans << endl;

        return 0;
}