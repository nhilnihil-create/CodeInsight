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

ll dp[2050][2050];

int main(){
    int n; cin >> n;
    vector<Pl> a(n);
    rep(i,n) cin >> a[i].first,a[i].second = i;
    sort(a.rbegin(),a.rend());
    rep(i,2050)rep(j,2050) dp[i][j] = -1;
    dp[0][0] = 0;
    rep(i,n){
        rep(j,i+1){
            if(dp[i][j] == -1) continue;
            int n1 = n-j-1;
            int n2 = i-j;
            if(n1-a[i].second >= 0) dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+(n1-a[i].second)*a[i].first);
            if(a[i].second-n2 >= 0) dp[i+1][j] = max(dp[i+1][j],dp[i][j]+(a[i].second-n2)*a[i].first);
        }
    }
    ll ans = 0;
    rep(i,n+1){
        ans = max(ans,dp[n][i]);
    }
    cout << ans << endl;
}

