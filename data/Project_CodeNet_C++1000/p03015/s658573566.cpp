#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const int INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()

const int MAX_N = 100002;
ll dp[MAX_N][2];
//dp[i][smaller = true]
//: A and Bのi桁目まで確定させ，その時点でA+BがL以下であることが確定しているような(A, B)の個数

void modadd(ll &a, ll b) {
    a = (a + b) % MOD;
}

int main() {
    string L; cin >> L;
    dp[0][0] = 1;
    rep(i, L.size()) {
        modadd(dp[i + 1][1], 3 * dp[i][1]);
        if(L[i] == '1') {
            modadd(dp[i + 1][1], dp[i][0]);
            modadd(dp[i + 1][0], 2 * dp[i][0]);
        }else {
            modadd(dp[i + 1][0], dp[i][0]);
        }
    }
    cout << (dp[L.size()][0] + dp[L.size()][1])%MOD << endl;
}
