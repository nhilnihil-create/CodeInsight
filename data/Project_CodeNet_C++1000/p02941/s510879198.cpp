/*Lucky_Glass*/
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=2e5;
#define fir first
#define sec second

int n;
int A[N+3],B[N+3];
bool fail;
priority_queue< pair<int,int> > que;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&A[i]);
    for(int i=0;i<n;i++){
        scanf("%d",&B[i]);
        if(B[i]!=A[i]) que.push(make_pair(B[i],i));
        if(B[i]<A[i]) fail=true;
    }
    if(fail) printf("-1\n"),exit(0);
    long long ans=0;
    while(!que.empty()){
        int it=que.top().sec;que.pop();
        int div=B[(it+1)%n]+B[(it-1+n)%n];
        long long delta=(B[it]-A[it])/div;
        if(!delta){fail=true;break;}
        B[it]-=div*delta;
        ans+=delta;
        if(B[it]==A[it]) continue;
        que.push(make_pair(B[it],it));
    }
    if(fail) printf("-1\n");
    else printf("%lld\n",ans);
    return 0;
}
