#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };  // i<4:4way i<8:8way
int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

ll dp[1000006][2][2]; // dp[i][j][k] := 長さがiで j=1で0を含む k=1で1を含む

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    dp[0][0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            rep(a,2)rep(b,2){
                if(j==0){
                    (dp[i+1][1][b] += dp[i][a][b])%=mod;
                }else if(j==1){
                    (dp[i+1][a][1] += dp[i][a][b])%=mod;   
                }else{
                    (dp[i+1][a][b] += dp[i][a][b])%=mod;
                }
            }
        }
    }
    cout << dp[n][1][1] % mod << endl;
}