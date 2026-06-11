#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using P = pair<int, int>;
const int mod = 1e9+7;

vector<bool> broken(100010, false);

const int INF = 1e9;
vector<ll> dp(100010,-1);

int rec(int i){
    if (dp[i] != -1) return dp[i];
    if (i == 0) return dp[0] = 1;
    int res = 0;
    if (!broken[i-1]) res += rec(i-1);
    if (i > 1 && !broken[i-2]) res += rec(i-2);
    return dp[i] = res % mod;
}


int main(){
    int n, m;
    cin >> n >> m;

    rep(i,m){
        int x;
        cin >> x;
        broken[x] = true;
    }

    cout << rec(n) << endl;
    // rep(i,n+1){
    //     printf("%d ", dp[i]);
    // }
    // printf("\n");
    return 0;
}
