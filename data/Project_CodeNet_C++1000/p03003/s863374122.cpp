#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int add(int i, int j) {
    if((i += j) >= mod) i -= mod;
    return i;
}

int A[2000];
int B[2000];
int dp[2000][2000];
int rp[2000][2000];
int n, m;

int f(int, int);
int d(int i, int j) {
    if(i >= n || j >= m) return 0;
    if(rp[i][j] > -1) return rp[i][j];
    return rp[i][j] = add(d(i, j + 1), (A[i] == B[j] ? f(i + 1, j + 1) : 0));
}

int f(int i, int j) {
    if(i >= n || j >= m) return 1;
    if(dp[i][j] > -1) return dp[i][j];
    int mx = f(i + 1, j);
    mx = add(mx, d(i, j));
    return dp[i][j] = mx;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> A[i];
    for(int i = 0; i < m; ++i)
        cin >> B[i];
    
    memset(rp, -1, sizeof rp);
    memset(dp, -1, sizeof dp);
    cout << f(0, 0);
    
    return 0;
}