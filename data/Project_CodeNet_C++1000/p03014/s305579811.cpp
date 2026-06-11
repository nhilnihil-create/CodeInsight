#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define sll(x) scanf("%lld",&x)
#define prll(x) printf("%lld ",x)
#define pri(x) printf("%d ",x)
#define si(x) scanf("%d",&x)
#define el cout << "\n"
#define pb push_back
#define f first
#define s second
#define arrondi(a) (long long)floor(a+0.5);
#define NIL -1
ll N=500005;
ll MAX=9223372036854775807;
ll MOD=1000000007;
long double PI =4*atan(1);
ll n,m;
vector <string> A;

ll nbr[2002][2002][4];
int main()
{
    IOS;
    cout.precision(30);
    string s;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        A.push_back(s);
    }
    ll ANS=0;
    memset(nbr,0,sizeof nbr);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (A[i-1][j-1]=='.')
            {
                nbr[i][j][0]=nbr[i][j-1][0]+1;
            }
        }

    }

    for (int j=1;j<=m;j++)
    {
        for (int i=1;i<=n;i++)
        {
            if (A[i-1][j-1]=='.')
            {
                nbr[i][j][1]=nbr[i-1][j][1]+1;
            }
        }

    }

    for (int i=n;i>=1;i--)
    {
        for (int j=m;j>=1;j--)
        {
            if (A[i-1][j-1]=='.')
            {
                nbr[i][j][2]=nbr[i][j+1][2]+1;
            }
        }
    }

    for (int j=m;j>=1;j--)
    {
        for (int i=n;i>=1;i--)
        {
            if (A[i-1][j-1]=='.')
            {
                nbr[i][j][3]=nbr[i+1][j][3]+1;
            }
        }
    }

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            ll ans=0;
            if (A[i-1][j-1]=='.')
            {
                for (int k=0;k<4;k++)
                {
                    ans+=nbr[i][j][k];
                }
                ANS=max(ANS,ans-3);
            }
        }
    }
    cout << ANS << "\n";
}

