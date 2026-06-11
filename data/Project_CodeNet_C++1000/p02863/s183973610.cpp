#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<ll, pair<ll, ll> > p;
 
#define MOD 1000000007
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, T;
    cin >> N >> T;

    vector<int> A(N + 2);
    vector<int> B(N + 2);

    for(int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
    }

    vector<vector<int> > dp1(N + 2, vector<int>(T));
    vector<vector<int> > dp2(N + 2, vector<int>(T));

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < T; j++) {
            dp1[i][j] = dp1[i - 1][j];
            if(j - A[i] >= 0) {
                dp1[i][j] = max(dp1[i][j], dp1[i - 1][j - A[i]] + B[i]);
            }
        }
    }

    for(int i = N; i >= 1; i--) {
        for(int j = 0; j < T; j++) {
            dp2[i][j] = dp2[i + 1][j];
            if(j - A[i] >= 0) {
                dp2[i][j] = max(dp2[i][j], dp2[i + 1][j - A[i]] + B[i]);
            }
        }
    }

    int ans = 0;

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < T; j++) {
            ans = max(ans, dp1[i - 1][j] + dp2[i + 1][T - 1 - j] + B[i]);
        }
    }

    cout << ans << endl;
}