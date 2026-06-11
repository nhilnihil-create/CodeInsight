#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;


const int maxn = 330;
const ll inf = 1e18;

int n, k;
ll dp[maxn][maxn][maxn];
ll a[maxn];


ll go(int i, int remove, int p) {
    if (i>n) return 0;
    if (~dp[i][remove][p]) return dp[i][remove][p];
    ll &res = dp[i][remove][p] = inf;

    if (remove>0) {
	res = min(res, go(i+1, remove-1, p));
    }
    res = min(res, max(0ll,a[i+1]-a[p])+go(i+1,remove,i+1));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n>>k;
    for (int i=1; i<=n; i++) {
	cin>>a[i];
    }
    
    memset(dp,-1,sizeof(dp));
    cout<<go(0,k,0)<<endl;    
    return 0;
}
