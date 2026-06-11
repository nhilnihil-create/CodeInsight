#include<bits/stdc++.h>
using namespace std;
namespace io{
    const int l=1<<20;
    char buf[l],*s,*t,c;
    inline void gc(){
        if(s==t){
            t=(s=buf)+fread(buf,1,l,stdin);
            c=s==t?EOF:*s++;
        }else c=*s++;
    }
    template<class IT>inline void gi(IT &x){
        x=0;gc();while(c<'0'||c>'9')gc();
        while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);gc();}
    }
    char buf0[20];int a;
    template<class IT>inline void pi(IT x){
        if(x<0){putchar('-');x=-x;}
        do buf0[++a]=x%10+48;while(x/=10);
        while(a)putchar(buf0[a--]);
        putchar('\n');
    }
};
using io::gi;
using io::pi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,ll > pil;
typedef pair<ll ,int> pli;
typedef pair<ll ,ll > pll;
typedef vector<int> vi;
typedef vector<ll > vl;
#define pque priority_queue
#define rep(i,l,r) for(i=(l);i<=(r);++i)
#define per(i,l,r) for(i=(l);i>=(r);--i)
#define REP(i,l,r) for(i=(l);i< (r);++i)
#define PER(i,l,r) for(i=(l);i> (r);--i)
#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define fi first
#define se second
template<class IT>inline void cmax(IT &a,IT b){if(a<b)a=b;}
template<class IT>inline void cmin(IT &a,IT b){if(b<a)a=b;}
const int N=5005;
int d[N];
ll solve(int k,int m){
    int i;ll s=0ll;
    REP(i,0,k)s+=(d[i]%m)?d[i]%m:m;
    return s;
}
int main(){
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int k,q,n,m,i,x;
    scanf("%d%d",&k,&q);
    REP(i,0,k)scanf("%d",&d[i]);
    while(q--){
        scanf("%d%d%d",&n,&x,&m);--n;
        printf("%d\n",n-(x%m+solve(k,m)*(n/k)+solve(n%k,m))/m);
    }
    return 0;
}