#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long

#define for(i,a,b) for (i=a; i<b; i++)
#define forb(i,a,b) for (i=a; i>b; i--)
#define all(S) S.begin(),S.end()
#define sort(S) sort(all(S))

const int inf = 1e9;
const ll INF = 1e18;

bool a[100][100];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    string s;
    int n,m,i,j;
    cin >> n >> m;
    for (i,0,n)
    {
        cin >> s;
        for (j,0,m)
            a[i][j]=(s[j]-'.');
    }
    int dp[100][100];
    dp[0][0]=a[0][0];
    for (i,1,n)
    {
        dp[i][0]=dp[i-1][0];
        if (a[i][0] && !a[i-1][0])
            dp[i][0]++;
    }
    for (j,1,m)
    {
        dp[0][j]=dp[0][j-1];
        if (a[0][j] && !a[0][j-1])
            dp[0][j]++;
    }
    for (i,1,n)
        for (j,1,m)
    {
        int q = dp[i-1][j];
        if (a[i][j] && !a[i-1][j])
            q++;
        int p = dp[i][j-1];
        if (a[i][j] && !a[i][j-1])
            p++;
        dp[i][j]=min(q,p);
    }
    cout << dp[n-1][m-1] << endl;
    return 0;
}
