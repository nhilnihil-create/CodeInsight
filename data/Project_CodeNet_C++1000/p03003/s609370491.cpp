#include<bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;
typedef pair<int,int> pi;
typedef long long int ll;

const int N = (int)2e3+5;

ll dp[N][N],sum[N][N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int> s(n+1),t(m+1);
    for(int i=1;i<=n;i++) {
        cin>>s[i];
    }
    for(int i=1;i<=m;i++) {
        cin>>t[i];
    }
    dp[0][0] = 1;
    for(int i=0;i<=m;i++) {
        sum[0][i] = 1;
    }
    for(int i=1;i<=n;i++) {
        memcpy(sum[i],sum[i-1],sizeof(sum[i]));
        for(int j=1;j<=m;j++) {
            if(s[i]==t[j]) {
                dp[i][j] = sum[i-1][j-1];
            }
            sum[i][j] += sum[i][j-1]-sum[i-1][j-1]+dp[i][j];
            sum[i][j] %= mod;
            if(sum[i][j]<0) sum[i][j] += mod;
        }
    }
    cout<<sum[n][m];
}
