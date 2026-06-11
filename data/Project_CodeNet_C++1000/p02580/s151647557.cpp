#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M=3e5+5;
int a[M];
int b[M];
map<pair<int,int>,bool>mp;
int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    while(q--)
    {
       int x,y;
       scanf("%d%d",&x,&y);
       a[x]++;
       b[y]++;
       mp[make_pair(x,y)]=1;
    }
    int ma=0,mb=0;
    for(int i=1;i<=n;i++)
    {
        ma=max(ma,a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        //printf("%d ",b[i]);
        mb=max(mb,b[i]);
    }
    vector<int>aa,bb;
    for(int i=1;i<=n;i++)
    {
       if(a[i]==ma) aa.push_back(i);
    }
    for(int i=1;i<=m;i++)
    {
        if(b[i]==mb) bb.push_back(i);
    }
    //int cnt=0;
    for(auto i:aa)
    {
        for(auto j:bb)
        {
              if(mp.count(make_pair(i,j))==0)
            {
                printf("%d\n",ma+mb);
                return 0;
            }

        }
    }

    //printf("+");
      //printf("%d %d\n",ma,mb);
    printf("%d\n",ma+mb-1);
    return 0;
}
