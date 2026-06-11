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

void work(){
    int N; scanf("%d",&N);
    printf("%d\n",(N-1)/2);
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





