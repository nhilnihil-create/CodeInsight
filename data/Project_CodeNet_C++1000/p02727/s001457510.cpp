#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define MAXN 100010
using namespace std;
int X,Y,A,B,C;
long long p[MAXN],q[MAXN],r[MAXN];
bool cmp(int a,int b){
    return a>b;
}
long long all[2*MAXN],head;
int main(){
    //freopen("data.in","r",stdin);
    scanf("%d %d %d %d %d",&X,&Y,&A,&B,&C);
    for(int i=1;i<=A;i++)
        scanf("%lld",&p[i]);
    for(int i=1;i<=B;i++)
        scanf("%lld",&q[i]);
    for(int i=1;i<=C;i++)
        scanf("%lld",&r[i]);
    sort(p+1,p+A+1,cmp);
    sort(q+1,q+B+1,cmp);
    sort(r+1,r+C+1,cmp);
    int R=0,G=0;
    for(int i=1;i<=A;i++){
        all[++head]=p[i];
        R++;
        if(R==X) break;       
    }
    for(int i=1;i<=B;i++){
        all[++head]=q[i];
        G++;
        if(G==Y) break;
    }
    //cout<<R<<" "<<G<<endl;
    int c=0;
    while(R<X){
        all[++head]=r[++c];
        R++;
    }
    while(G<Y){
        all[++head]=r[++c];
        G++;
    }
    //for(int i=1;i<=head;i++) cout<<all[i]<<" "; cout<<endl;
    sort(all+1,all+head+1,cmp);
    c++;
    for(int i=head;i>=1&&c<=C;i--,c++){
        if(all[i]>r[c]) break;
        all[i]=r[c];
    }
    long long ans=0;
    for(int i=1;i<=head;i++){
        ans=ans+all[i];
    }
    cout<<ans<<endl;
}