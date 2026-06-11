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
bool fn(vector<vector<lg>>& gr,vector<vector<lg>>& nodes)
{
    lg l = gr.size();
    lg n = nodes.size();
    lg j=0;

    if(n>l) return false;

    for(lg i=0;i<l;i++)
    {
        if(nodes[j][0]==gr[i][0] && nodes[j][1]==gr[i][1])
            j++;

        if(j==n) return true;

        if(nodes[j][0]<gr[i][0])
            return false;
    }
    return false;
}
int main()
{
    lg n,m,t;
    cin>>n>>m>>t;

    vector<lg>rows(n,0);
    vector<lg>cols(m,0);
    vector<vector<lg>>gr;
    vector<lg>cord(2,0);
    for(lg i=0;i<t;i++)
    {
        lg a,b;
        cin>>a>>b;
        cord[0]=a-1;
        cord[1]=b-1;
        gr.pb(cord);
        rows[a-1]++;
        cols[b-1]++;
    }
    sort(gr.begin(),gr.end());
    lg r=0,c=0;
    for(lg i=0;i<n;i++)
        r=max(r,rows[i]);
    vector<lg>rr;
    for(lg i=0;i<n;i++)
        if(rows[i]==r)
            rr.pb(i);

    for(lg i=0;i<m;i++)
        c=max(c,cols[i]);
    vector<lg>cc;
    for(lg i=0;i<m;i++)
        if(cols[i]==c)
            cc.pb(i);

    lg maxnum=r+c;

    vector<vector<lg>>nodes;

    lg x=rr.size();
    lg y=cc.size();
    if(x*y>t)
    {
        cout<<maxnum<<endl;
    }
    else
    {
        for(lg i=0;i<x;i++)
            for(lg j=0;j<y;j++)
            {
                cord[0]=rr[i];
                cord[1]=cc[j];
                nodes.pb(cord);
            }

        if(fn(gr,nodes))
            maxnum--;

        cout<<maxnum<<endl;
    }
}

