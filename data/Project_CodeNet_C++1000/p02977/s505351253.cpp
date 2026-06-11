//2019.7.14 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define eps 5.6e-8
#define RG register
#define db double
#define lb long db
#define pc(x) __builtin_popcount(x)
typedef pair<int,int> Pair;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
#define gc getchar
//inline char gc() {
//    static char buf[100000],*p1,*p2;
//    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
//}
inline int read() {
    res s=0,ch=gc();
    while(ch<'0'||ch>'9')ch=gc();
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s;
}
//inline int read() {
//    res s=0,ch=gc(),w=1;
//    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s*w;
//}
//inline LL Read() {
//    RG LL s=0;
//    res ch=gc();
//    while(ch<'0'||ch>'9')ch=gc();
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s;
//}
//inline LL Read() {
//    RG LL s=0;
//    res ch=gc(),w=1;
//    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s*w;
//}
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace MAIN{
    int n;
    inline void MAIN(){
        n=read();
        if(n==(n&-n)){puts("No");return;}
        puts("Yes");
        for(res i=2;i<=n-1;i+=2){
            printf("%d %d\n",i+1+n,i+n);
            printf("%d %d\n",i+n,1);
            printf("%d %d\n",1,i+1);
            printf("%d %d\n",i+1,i);
        }
        printf("%d %d\n",1+n,3+n);
        if(n%2==0){
            res p=n^1;
            res i=int(log2(p));
            res q=1<<i,r=p^q;
            if(q&1);
            else q+=n;
            if(r&1);
            else r+=n;
            printf("%d %d\n",n,q);
            printf("%d %d\n",n+n,r);
        }
    }
}
int main() {
//    srand((unsigned)time(NULL));
//    freopen("zao.in","r",stdin);
//    freopen("std.out","w",stdout);
    MAIN::MAIN();
    return 0;
}
