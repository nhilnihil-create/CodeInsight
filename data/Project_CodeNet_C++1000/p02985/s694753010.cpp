#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define ll long long
int cnt[100005];
int book[100005];
ll son[100005];
const ll mod=1000000007;
ll n,k;
vector <int> e[100005];
int main()
{
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        cnt[u]++;
        cnt[v]++;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int p=n;
    while(p>1)
    {
        for(int i=1;i<=n;i++)
        {
            if(cnt[i]==1)
            {
                book[i]=1;
                cnt[i]--;
                p--;
                for(int j=0;j<e[i].size();j++)
                {
                    if(book[e[i][j]]==0)
                    {
                        son[e[i][j]]++;
                        cnt[e[i][j]]--;
                        break;
                    }
                }
            }
        }
    }
    int flag;
    for(int i=1;i<=n;i++)if(book[i]==0)
    {
        flag=i;
        break;
    }

    ll ans=k;
    while(son[flag]--)ans=(ans*(k-son[flag]-1))%mod;
    son[flag]=0;
    for(int i=1;i<=n;i++)
    {
        if(son[i]==0)continue;
        if(k<=son[i]+1)
        {
            printf("0");
            return 0;
        }
        while(son[i]--)ans=(ans*(k-son[i]-2))%mod;
    }
    printf("%lld",ans);
    return 0;
}
