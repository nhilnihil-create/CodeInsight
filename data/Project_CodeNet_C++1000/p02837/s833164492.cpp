#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >

const int N=15;
vector<ii> v[N];
int a[N];
int ans=0;
bool vis[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int sz;
        scanf("%d",&sz);
        for(int j=0; j<sz; j++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            ii z;
            z.F=x-1;
            z.S=y;
            v[i].push_back(z);
        }
    }
    int ans=0;
    for(int msk=0; msk<pow(2,n); msk++)
    {
        bool q=1;
        for(int i=0; i<n; i++)
        {

            if((1<<i) & msk)
                for(auto x:v[i])
                {
                    if(x.S==1 && ((1<<x.F)&msk)==0){
                        q=0;
                        //cout<<msk<<" "<<i<<endl;
                    }
                    if(x.S==0 && (1<<x.F & msk))
                        q=0;
                }
            if(!q)
                break;
        }
        if(!q)
            continue;
        ans=max(ans,__builtin_popcount(msk));
    }
cout<<ans;

}
