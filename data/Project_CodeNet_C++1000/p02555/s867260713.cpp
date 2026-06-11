#include "bits/stdc++.h"
using namespace std;
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int inf = 1e9+7;
const int N = 2e3+9;
int dp[N];

void calc(int n) {
    dp[0] = 1;
    for(int sum=3;sum<=n;++sum) {
        for(int coin=3;coin<=sum;++coin) {
            dp[sum] += dp[sum-coin];
            dp[sum] %= inf;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int a,b,n;
    cin>>n;
    calc(n);
    cout<<dp[n]<<endl;
    return 0;
}