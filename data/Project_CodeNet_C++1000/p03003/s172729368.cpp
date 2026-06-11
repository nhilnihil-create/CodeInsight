#include<bits/stdc++.h>
#define prArr(Arr,n) for(int _=0;_<n;_++)   cout<<(Arr)[_]<<" ";
using namespace std;
const int INF=(int)0x3f3f3f3f;
const int MOD=(int)1e9+7;
const double eps=1e-6;
long long dp[2003][2003],pref[2003][2003];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1),b(m+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    dp[0][0]=pref[0][0]=1;
    for(int i=1;i<=n;i++)
        pref[i][0]=1;
    for(int i=1;i<=m;i++)
        pref[0][i]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dp[i][j]=(a[i]==b[j]?pref[i-1][j-1]:0),
            pref[i][j]=(pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+dp[i][j]+MOD)%MOD;
    cout<<pref[n][m];
    return 0;
}

