#include<bits/stdc++.h>
using namespace std;

vector<long long>adj[100002];
long long ara[100004],vis[100002],mod=1000000007,ans,k;

long long bigmod(long long n,long long p)
{
     if(p==0)return 1;
     if(p%2==0)
     {
         long long ret=bigmod(n,p/2);
         return ((ret%mod)*(ret%mod))%mod;
     }
     else
        return ((n%mod)*(bigmod(n,p-1)%mod))%mod;
}

void bfs(long long src)
{

    vis[src]=1; long long sz=adj[src].size(); long long lp,v,u,x,y,z,p,q;
    queue<long long>qu; qu.push(src);

    while(!qu.empty())
    {
        v=qu.front(); qu.pop();

        sz=adj[v].size();

        if(v==1){  x=sz; y=k-1;  }
        else{  x=sz-1; y=k-2;  }

        if(x>0)
        {
            if(y<x){  ans=0; break; }
            else
            {
                p=ara[y-x]; q=bigmod(p,mod-2); z=(ara[y]*q)%mod; ans=(ans*z)%mod;
                //cout<<v<<"     "<<x<<" "<<y<<"      "<<p<<" "<<q<<" "<<z<<endl;
            }
        }

        if(ans==0)break;

        for(lp=0;lp<sz;lp++)
        {
            u=adj[v][lp]; if(vis[u]==0){   qu.push(u); vis[u]=1;  }
        }
    }


}

int main()
{



    long long n,m,i,j,a,b;
    scanf("%lld %lld",&n,&k);

    for(i=1;i<=n-1;i++)
    {
        scanf("%lld %lld",&a,&b);  adj[a].push_back(b);  adj[b].push_back(a);
    }

    ara[0]=1; for(i=1;i<=100001;i++){  ara[i]=(ara[i-1]*i)%mod;   }

    ans=k; bfs(1);
    printf("%lld\n",ans);


    return 0;
}



