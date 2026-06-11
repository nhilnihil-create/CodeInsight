#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int N=2e5+10,mod=1e9+7;
typedef long long ll;
int h[N],ne[N],e[N],idx;
bool st[N];
queue<int>q;
void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int main()
{
    memset(h,-1,sizeof h);
    int n,k,a,b;
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        add(a,b);add(b,a);
    }
    int root=1;
    st[1]=true;
    ll res=1;
    res=res*k%mod;
    int cnt=0;
    for(int i=h[1];~i;i=ne[i])
    {
        int j=e[i];
        if(st[j])   continue;
        q.push(j);
        st[j]=true;
        if(k-cnt-1<=0)  res=0;
        res=res*(k-cnt-1)%mod;
        cnt++;
    }
    while(q.size())
    {
        int cnt=0;
        int t=q.front();
        q.pop();
        for(int i=h[t];~i;i=ne[i])
        {
            int j=e[i];
            if(st[j])   continue;
            q.push(j);
            st[j]=true;
            if(k-cnt-2<=0)  res=0;
            res=res*(k-cnt-2)%mod;
            cnt++;
        }
    }
    printf("%lld",res);
}