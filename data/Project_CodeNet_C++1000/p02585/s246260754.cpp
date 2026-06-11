#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=5010;
ll dist[N][N],circle[N],mark[N];
bool st[N];
int pos[N],n;
ll k;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>pos[i];
    for(int i=1;i<=n;i++) cin>>mark[i];
    for(int i=1;i<=n;i++)
    {
        memset(st,0,sizeof st);
        int j=pos[i],idx=0;
        while(!st[j])
        {
            st[j]=1;
            idx++;
            dist[i][idx]=dist[i][idx-1]+mark[j];
            j=pos[j];
        }
        circle[i]=idx;
        
    }
    ll res=-1e18;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=circle[i];j++)
        {
            ll x=dist[i][j];
            if(k<j) break;
            if(dist[i][circle[i]]>=0) x+=(k-j)/circle[i]*dist[i][circle[i]];
            res=max(res,x);
        }
    cout<<res<<endl;
    return 0;
}
