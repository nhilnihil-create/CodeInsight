#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

const int MAX_N = 2005;
const ll MOD = 1000000007; 

int n, m, A[MAX_N], B[MAX_N];

ll DP[MAX_N][MAX_N];

int main() {
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    for(int i = 1; i <= m; i++) {
        cin >> B[i];
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            DP[i][j] = (DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1] + MOD) % MOD;
            if(A[i] == B[j]) {
                DP[i][j] = (DP[i][j] + DP[i - 1][j - 1] + 1) % MOD;
            }
        }
    }
    
    cout << (DP[n][m] + 1) % MOD;
    
    return 0;
}