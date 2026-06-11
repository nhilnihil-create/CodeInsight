#include<bits/stdc++.h>
#define lg long long int
#define loop(i,s,e) for(lg i=s;i<=e;i++)
#define iloop(i,s,e) for(lg i=e;i>=s;i--)
#define pb push_back
#define mp make_pair
using namespace std;

lg min(lg a,lg b)
{return a<b?a:b;}
lg max(lg a,lg b)
{return a>b?a:b;}
lg lcm(lg a ,lg b)
{
    return (a*b)/__gcd(a,b);
}

lg ans,n,m,k;;
void sol(vector<vector<lg>>& gr,vector<lg> rows,vector<lg> cols,lg i,lg j,lg now)
{
    if(now<k)
    {
        return ;
    }
    if(i==n)
    {
        if(j==m)
        {
            if(now==k) ans++;
        }
        else
        {
            sol(gr,rows,cols,i,j+1,now);
            sol(gr,rows,cols,i,j+1,now-cols[j]);
        }
    }
    else
    {
        sol(gr,rows,cols,i+1,j,now);
        for(lg l=0;l<m;l++)
        {
            if(gr[i][l]==1) cols[l]--;
        }
        sol(gr,rows,cols,i+1,j,now-rows[i]);
    }
}

int main()
{
    ans=0;

    cin>>n>>m>>k;

    vector<vector<lg>>gr(n,vector<lg>(m,0));
    vector<lg>rows(n,0);
    vector<lg>cols(m,0);
    lg tot=0;
    for(lg i=0;i<n;i++)
    {
        for(lg j=0;j<m;j++)
        {
            char a;
            cin>>a;
            if(a==35)
            {
                cols[j]++;
                rows[i]++;
                gr[i][j]=1;
                tot++;
            }
        }
    }
    sol(gr,rows,cols,0,0,tot);
    cout<<ans<<endl;
}
