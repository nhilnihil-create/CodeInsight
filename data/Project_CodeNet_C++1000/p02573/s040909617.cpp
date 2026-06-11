#include<bits/stdc++.h>
#define ks ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fr first
#define sc second
#define pb push_back
#define pf push_front
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pa;
template<class T>inline void read(T &res){
    char c;T flag=1;
    while((c=getchar())<'0'||c>'9')if(c=='-')flag=-1;res=c-'0';
    while((c=getchar())>='0'&&c<='9')res=res*10+c-'0';res*=flag;
}
void wenjian(){freopen("concatenation.in","r",stdin);freopen("concatenation.out","w",stdout);}
void tempwj(){freopen("hash.in","r",stdin);freopen("hash.out","w",stdout);}
ll gcd(ll a,ll b){return b == 0 ? a : gcd(b,a % b);}
ll qpow(ll a,ll b,ll mod){a %= mod;ll ans = 1;while(b){if(b&1)ans=ans*a%mod;a=a*a%mod;b >>= 1;}return ans;}
struct chongzai{int c; bool operator<(const chongzai &b )const{ return c>b.c; } }s;

const int maxn=4e5+177;
const ll mod=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
int maxx=1;
int fa[maxn],siz[maxn];
int d[maxn];
int get(int now){
    if(now==fa[now]){
        return now;
    }
    int root=get(fa[now]);
    d[now]+=d[fa[now]];
    return fa[now]=root;
}

void bcj(int x,int y){
    int xx=get(x);
    int yy=get(y);

    if(xx!=yy){
        fa[xx]=yy;
        d[xx]=siz[yy];
        siz[yy]+=siz[xx];
        maxx=max(maxx,siz[yy]);
    }

}


int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++){
        fa[i]=i;
        siz[i]=1;
    }

    int a,b;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        bcj(a,b);
    }
    printf("%d\n",maxx);


}
