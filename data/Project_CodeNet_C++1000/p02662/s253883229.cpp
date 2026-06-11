#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 998244353;
const int maxn = 3030;



ll dp[maxn][maxn];
ll n, s;
ll a[maxn];

void add(ll& x, ll y) {
    x+=y;
    x%=mod;
}

	 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n>>s;

    for (int i=0; i<n; i++) {
	cin>>a[i];
    }

    dp[0][0]=1;

    for (int i=0; i<n; i++) {
	for (int j=0; j<=s; j++) {
	    add(dp[i+1][j], 2LL*dp[i][j]);
	    if (j+a[i]<=s) {
		add(dp[i+1][j+a[i]], dp[i][j]);
	    }
	}
    }


    cout<<dp[n][s]<<endl;  

    return 0;
}
