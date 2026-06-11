#include<iostream>
#include<cstring>
#include<iostream>
using namespace std;

typedef long long LL;
const int N=3e5+10;
LL n,m,w;
int r[N];
int c[N];
int qr[N],qc[N];
int r_max,c_max;
int main(){
    scanf("%lld%lld%lld",&n,&m,&w);
    for(LL i=0;i<w;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        r[a]++;
        c[b]++;
        r_max=max(r_max,r[a]);
        c_max=max(c_max,c[b]);
        qr[i]=a;
        qc[i]=b;
    }
    LL R=0,C=0;
    for(int i=1;i<=n;++i){
        if(r_max==r[i]) R++;
    }
    for(int i=1;i<=m;++i){
        if(c_max==c[i]) C++;
    }
    LL cnt=0;
    for(LL i=0;i<w;++i){
        int a,b;
        a=qr[i];
        b=qc[i];
        if(r[a]==r_max&&c[b]==c_max) cnt++;
    }
    LL t=R*C;
    LL res=r_max+c_max;
    if(t==cnt) res--;
    cout<<res<<endl;
    return 0;
}
