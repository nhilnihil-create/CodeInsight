#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <climits>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <list>
#include <bitset>
#include <vector>
using namespace std;

#define I64d_OJ

//#ifdef I64d_OJ
//#define LL __int64
//#endif // I64d_OJ
#ifdef I64d_OJ
#define LL long long
#endif // I64d_OJ

typedef unsigned LL ULL;
typedef unsigned uint;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<LL,LL> pLL;
typedef vector<int> vi;

inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-f; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define ls rt<<1
#define rs rt<<1|1
#define MID(a,b) (((LL)(a)+(LL)(b))>>1)
#define absx(a) ((a)<0?-(a):(a))
#define MK(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define lowbit(x) ((x)&-(x))

#define lc c[x][0]
#define rc c[x][1]

template< typename T >
inline void Max(T &a,T &b){if(a<b) a=b;}
template< typename T>
inline void Min(T &a,T &b){if(a>b) a=b;}

const double pi=(double)acos(-1.0);
const double eps=(double)1e-8;
const int INF = (int) 0x3f3f3f3f;
const int MOD = (int) 1e9+7;
const int MAXN =(int) 5e3+10;
const int MAXM = (int) 3e6+10;

///--------------------START-------------------------
int k,q;
int d[MAXN],dd[MAXN];
LL s[MAXN],szero[MAXN];

void work(){
    scanf("%d%d",&k,&q);
    for(int i=1;i<=k;i++){
        scanf("%d",&d[i]);
    }
    while(q--){
        int n,x,m;
        LL ans=0,a0,an;
        scanf("%d%d%d",&n,&x,&m);
        for(int i=1;i<=k;i++){
            dd[i]=d[i]%m;
            s[i]=s[i-1]+dd[i];
            szero[i]=szero[i-1]+(dd[i]==0);
        }
//        for(int i=1;i<=k;i++) printf("%lld ",szero[i]);
//        printf("\n");
        a0=x;
        LL p=(n-1)/k;
        int q=(n-1)%k;
        an=(LL)x+(p*s[k]+s[q]);
//        printf("q = %lld\n",n-1-p*k);
//        printf("p = %lld , q = %d\n",p,q);
//        printf("an = %lld , a0 = %lld\n",an,a0);
        ans+=(p*szero[k]+szero[q]);
        ans+=an/m-a0/m;
//        printf("%lld %lld\n",p*szero[k]+szero[q],an/m-a0/m);
        printf("%lld\n",(LL)n-1-ans);
    }
}

///--------------------END-------------------------
int main(){
#ifdef NNever
//freopen("data.in","r",stdin);
///freopen("out.txt","w",stdout);
#endif // NNever
    work();
    return 0;
}




