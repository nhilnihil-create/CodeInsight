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

ll k,dp[10][10];

void go(ll s, ll c, ll cur, ll ans)
{
    ll ans1 = ans*10+c;
    if (s==0)
    {
        cout << ans1 << endl;
        return;
    }
    ll cur1 = cur;
    if (c>0)
        cur1+=dp[s-1][c-1];
    if (cur1>=k)
    {
        cur1-=dp[s-1][c-1];
        go(s-1,c-1,cur1,ans1);
        return;
    }
    cur1+=dp[s-1][c];
    if (cur1>=k)
    {
        cur1-=dp[s-1][c];
        go(s-1,c,cur1,ans1);
        return;
    }
    go(s-1,c+1,cur1,ans1);
    return;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int i,j,p=0;
    cin >> k;
    for (i,0,10)
        dp[0][i]=1;

    for (i,1,10)
    {
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][9]=dp[i-1][9]+dp[i-1][8];
        for (j,1,9)
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1];
    }

    for (i,0,10)
    {
        for (j,1,10)
        {
            p+=dp[i][j];
            if (p>=k)
            {
                go(i,j,p-dp[i][j],0);
                break;
            }
        }
        if (p>=k)
            break;
    }
    return 0;
}
