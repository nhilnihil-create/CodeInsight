#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll MOD=998244353;
const int N=3099;
int n, s, a[N];
ll dp[N][N];
int main() {
    IOS; cin >> n >> s;
    for(int i=0; i<n; ++i) {
        cin >> a[i];
    }
    dp[0][0]=1LL;
    for(int elem=0; elem<n; ++elem) {
        for(int trenS=0; trenS<=s; ++trenS) {
            dp[elem+1][trenS]+=2*dp[elem][trenS];
            dp[elem+1][trenS]%=MOD;
            if(trenS+a[elem]<=s) {
                dp[elem+1][trenS+a[elem]]+=dp[elem][trenS];
                dp[elem+1][trenS+a[elem]]%=MOD;
            }
        }
    }
    cout << dp[n][s];
    return 0;
}
