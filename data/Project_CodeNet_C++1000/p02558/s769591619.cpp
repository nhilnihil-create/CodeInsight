#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int p[2*100005];
int r[2*100005];
void make_set(int x)
{
    p[x]=x;
}
int Find(int x)
{
    if(p[x]==x)return x;
    else return p[x]=Find(p[x]);
}
void unit(int x,int y)
{
    x=Find(x);
    y=Find(y);
    if(r[x]<r[y]){
        p[x]=y;
    }
    else{
        p[y]=x;
        if(r[x]==r[y])r[x]++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)make_set(i);
    while(m-->0){
        int t;
        cin>>t;
        if(t==0){
            int x,y;
            cin>>x>>y;
            unit(x,y);
        }
        if(t==1){
            int x,y;
            cin>>x>>y;
            if(Find(x)==Find(y))cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
}
