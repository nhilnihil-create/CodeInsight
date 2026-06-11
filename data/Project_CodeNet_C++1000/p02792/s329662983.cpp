#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define fast                                                                   \
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define fo(i,a,n) for (i = a; i <= n; i++)
#define F first
#define S second
#define pii pair<int,int>
#define sz size()
#define all(v) v.begin(),v.end()
#define pb push_back
#define pf push_front    
#define PB pop_back
#define pll pair<long long, long long>
#define vi vector<int>
#define vl vector<int>
#define mp make_pair
#define mod 1000000007
typedef unsigned long long ull;
const int N = 200005;
const int MOD = 998244353 ;


void solve(){
    int n, ans = 0;
    cin>>n;
    int dp[10][10];
    f(i,10)f(j,10)dp[i][j] = 0;
    for(int i = 1; i<= n; i++){
        int k = i;
        while(k >= 10)k /= 10;
        dp[k][i%10]++;
    }
    for(int i = 1; i<= n; i++){
        int k = i;
        while(k >= 10)k /= 10;
        ans += dp[i%10][k];
    }
    cout<<ans;
}

int32_t main() {
    fast
    int t;
    t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
