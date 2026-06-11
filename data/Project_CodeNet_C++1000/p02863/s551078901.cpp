#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N,T;
    cin >> N >> T;
    vector<int> A(N);
    vector<int> B(N);
    rep(i,N){
        cin >> A[i] >> B[i];
    }
    vector<vector<int> > dp1(N + 1, vector<int> (T));
    rep(i,N + 1){
        rep(j,T){
            dp1[i][j] = 0;
        }
    }
    rep(i,N){
        rep(j,T){
            dp1[i + 1][j] = max(dp1[i + 1][j], dp1[i][j]);
            if (j + A[i] < T){
                dp1[i + 1][j + A[i]] = max(dp1[i + 1][j + A[i]], dp1[i][j] + B[i]);
            }
        }
    }
    vector<vector<int> > dp2(N + 1, vector<int> (T));
    rep(i,N + 1){
        rep(j,T){
            dp2[i][j] = 0;
        }
    }
    for (int i = N - 1; i >= 0; i--){
        rep(j,T){
            dp2[i][j] = max(dp2[i][j] , dp2[i + 1][j]);
            if (j + A[i] < T){
                dp2[i][j + A[i]] = max(dp2[i][j + A[i]], dp2[i + 1][j] + B[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++){
        rep(j,T){
            ans = max(ans, dp1[i][j] + B[i] + dp2[i + 1][T - 1 - j]);
        }
    }
    cout << ans << endl;
}
