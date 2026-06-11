#include<bits/stdc++.h>
using namespace std;

struct info
{
    int a,b,c;
};

bool s[101][101][101];

int val(info x)
{
    int ans=x.a*x.a+x.b*x.b+x.c*x.c+x.a*x.b+x.b*x.c+x.c*x.a;
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int cnt[n+1]={0};
    queue<pair<int,info>> p;
    p.push({6,{1,1,1}});
    s[1][1][1]=1;
    while(!p.empty())
    {
        pair<int,info> x=p.front(); p.pop();
        if(x.first<=n)
            cnt[x.first]++;
        info z=x.second;
        z.a++; int k=val(z);
        if(k<=n && !s[z.a][z.b][z.c]) 
        {
            p.push({k,z});
            s[z.a][z.b][z.c]=1;
        }
        z.a--; z.b++; k=val(z);
        if(k<=n && !s[z.a][z.b][z.c]) 
        {
            p.push({k,z});
            s[z.a][z.b][z.c]=1;
        }
        z.b--; z.c++; k=val(z);
        if(k<=n && !s[z.a][z.b][z.c]) 
        {
            p.push({k,z});
            s[z.a][z.b][z.c]=1;
        }
    }
    for(int i=1; i<=n; i++)
        cout<<cnt[i]<<endl;
    return 0;
}