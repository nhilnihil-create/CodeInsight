#include<bits/stdc++.h>
#define sd(a) scanf("%lld",&a)
#define int long long
using namespace std;
const int maxn=2e5+10;
struct node{
    int num,pos;
    bool operator<(const node a)const{
        return num==a.num?pos>a.pos:num<a.num;
    }
};
priority_queue<node>q;
int a[maxn],b[maxn];
main(){
    int n;
    sd(n);
    for(int i=1;i<=n;++i){
        sd(a[i]);
    }
    node tmp;
    for(int i=1;i<=n;++i){
        sd(b[i]);
        tmp.num=b[i];
        tmp.pos=i;
        q.push(tmp);
    }
    int ans=0;
    while(!q.empty()){
        node now=q.top();
        q.pop();
        int pos=now.pos;
        if(b[pos]==a[pos])continue;
        int d=b[pos]-a[pos];
        int cnt=b[pos-1?pos-1:n]+b[pos+1==n+1?1:pos+1];
        if(d<cnt||b[pos]<a[pos]){puts("-1");return 0;}
        ans+=d/cnt;
        b[pos]-=d/cnt*cnt;
        tmp.num=b[pos];
        tmp.pos=pos;
        q.push(tmp);
    }
    printf("%lld\n",ans);
}
