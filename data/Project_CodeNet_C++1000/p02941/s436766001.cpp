#include<queue>
#include<cstdio>
using namespace std;

int read(){
    int x=0;bool f=0;char c=getchar();
    while(c<'0'||c>'9') f|=c=='-',c=getchar();
    while(c>='0'&&c<='9') x=x*10+(c^48),c=getchar();
    return f?-x:x;
}

#define MAXN 200000
int N,A[MAXN+5],B[MAXN+5];

int main(){
    //freopen("hopeless.in" ,"r", stdin);
    //freopen("hopeless.out","w",stdout);
    priority_queue<pair<int,int>,vector<pair<int,int> >,less<pair<int,int> > > Q;
    N=read();
    for(int i=1;i<=N;i++)
        A[i]=read();
    for(int i=1;i<=N;i++)
        Q.push(make_pair(B[i]=read(),i));
    long long Ans=0;
    while(!Q.empty()){
        int i=Q.top().second;Q.pop();
        int j=(i-2+N)%N+1,k=i%N+1;
        int Sum=B[j]+B[k],Min=max(max(B[j],B[k]),A[i]);
        int x=(B[i]-Min+Sum-1)/Sum;
        Ans+=x;
        B[i]-=Sum*x;
        if(B[i]<A[i])
            return puts("-1"),0;
        if(B[i]>A[i])
            Q.push(make_pair(B[i],i));
    }
    for(int i=1;i<=N;i++)
        if(A[i]!=B[i])
            return puts("-1"),0;
    printf("%lld",Ans);
}
