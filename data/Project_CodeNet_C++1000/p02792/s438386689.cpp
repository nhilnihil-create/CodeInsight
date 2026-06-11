#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <cstdint>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000000
#define MAX 200001

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const ll MOD = 1000000007;

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

ll solve(string a, string N){
    int n = N.size();
    int fr = a[0] - '0';
    int ba = a[a.size()-1] - '0';
    ll dp[6][2][2];
    dp[0][0][0] = 1;
    rep(i,n)rep(smaller,2)rep(flag,2){
        int d = N[i] - '0';
        for(int j = 0; j <= (smaller ? 9:d); j++){
            dp[i+1][smaller || j < d][flag] += dp[i][smaller][flag];
        }
    }
    return dp[n][0][1] + dp[n][1][1];
}

int main(){
    int N;
    cin >> N;
    vector<vector<int>> c(10,vector<int>(10,0));
    for(int i = 1; i <= N; i++){
        int now = i;
        int d = 1;
        while(now >= 10){
            now /= 10;
            d*=10;
        }
        c[i/d][i%10]++;
    }
    ll ans = 0;
    rep(i,10)rep(j,10) ans += c[i][j] * c[j][i];
    cout << ans << endl;
}