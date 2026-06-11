#include <iostream>
using namespace std;
int mod = 1e9+7;
typedef long long int64;
#define rep(i, N) for(int i = 0; i < N; ++i)

// 赤+1C1  ×  青-1C0
// 赤+1C2  ×  青-1C1
//   ・　　　　　・
//   ・          ・
// 赤+1C青 ×  青-1C青-1

int64 inv(int64 a, int64 mo) {
	a %= mo;
	int64 v[] = { 0, 1, mo };
	int64 u[] = { 1, 0, a };
	while (v[2] != 1) {
		if (v[2] < u[2]) {
			int64 tmp[] = {v[0], v[1], v[2]};
			v[0] = u[0];v[1] = u[1];v[2] = u[2];
			u[0] = tmp[0];u[1] = tmp[1];u[2] = tmp[2];
			continue;
		}
		int64 coe = v[2] / u[2];
		for (int i = 0; i < 3; ++i) v[i] = v[i] - u[i] * coe;
	}
	return v[0] < 0 ? v[0] + mo : v[0];
}

int main(){
    int64 N, K;
    cin >> N >> K;
    int64 A = N - K;

    int64 ans;
    rep(i, K) {
        ans = 1;

        // A+1Ci+1 * K-1Ci

        rep(j, i+1) {
            ans *= (A+1-j);
            ans %= mod;
        }

        rep(j, i+1) {
            ans *= inv(i+1-j, mod);
            ans %= mod;
        }
        
        rep(j, i) {
            ans *= (K-1-j);
            ans %= mod;
        }

        rep(j, i) {
            ans *= inv(i-j, mod);
            ans %= mod;
        }

        cout << ans << "\n";
    }
    return 0;
}
