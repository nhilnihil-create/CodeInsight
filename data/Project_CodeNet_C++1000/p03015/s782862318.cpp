#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

ll dp[100010][2];

int main(){
    string L; cin >> L;
    int n = L.size();
    dp[0][0] = 1;
    rep(i,n){
        dp[i+1][1] += dp[i][1]*3%MOD;
        dp[i+1][1] %= MOD;
        if(L[i] == '0'){
            dp[i+1][0] += dp[i][0];
            dp[i+1][0] %= MOD;
        }
        else{
            dp[i+1][0] += dp[i][0]*2%MOD;
            dp[i+1][0] %= MOD;
            dp[i+1][1] += dp[i][0];
            dp[i+1][1] %= MOD;
        }
    }
    cout << (dp[n][0]+dp[n][1])%MOD << endl;
}
