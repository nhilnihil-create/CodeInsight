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

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n,i,j,a[4010],dp[4010][3];
    string s;
    cin >> n >> s;
    for (i,0,n)
    {
        a[i]=0;
        if (s[i]=='G')
            a[i]=1;
        if (s[i]=='B')
            a[i]=2;
    }
    dp[0][0]=dp[0][1]=dp[0][2]=0;
    dp[0][a[0]]=1;
    for (i,1,n)
    {
        for (j,0,3)
            dp[i][j]=dp[i-1][j];
        dp[i][a[i]]++;
    }
    ll k = 0;
    for (i,0,n-3)
        for (j,i+1,n-1)
            if (a[i]!=a[j])
        {
            int q = 3-a[i]-a[j];
            k+=(dp[n-1][q]-dp[j][q]);
            if (j+j-i<n && a[j+j-i]==q)
                k--;
        }
    cout << k << endl;
    return 0;
}
