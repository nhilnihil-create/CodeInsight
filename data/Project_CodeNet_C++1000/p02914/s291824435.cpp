#include<bits/stdc++.h>
#define de(x) cout<<#x<<"="<<x<<endl
#define dd(x) cout<<#x<<"="<<x<<" "
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define repd(i,a,b) for(int i=a;i>=(b);--i)
#define repp(i,a,b,t) for(int i=a;i<(b);i+=t)
#define mt(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp(u,v) make_pair(u,v)
#define sz(a) (int)a.size()
#define pb push_back
#define PI acos(-1.0)
#define qc std::ios::sync_with_stdio(false)
#define all(a) a.begin(),a.end()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef double db;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;

const ll mod = 1000000007;
const int N = 1e5+6;
const int M = 2e6+6;
const double eps = 1e-6;
const int inf = 0x3f3f3f3f;

bool eq(const db &a, const db &b) { return fabs(a - b) < eps; }
bool ls(const db &a, const db &b) { return a + eps < b; }
bool le(const db &a, const db &b) { return eq(a, b) || ls(a, b); }
ll gcd(ll a,ll b) { return a==0?b:gcd(b%a,a); };
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
ll kpow(ll a,ll b) {ll res=1;a%=mod; if(b<0) return 1; for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll read(){
    ll x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//inv[1]=1;
//for(int i=2;i<=n;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
ll a[N];
ll p[62];
void add(ll x) {
    repd(i, 60, 0) {
        if(!(x&(1ll<<i))) continue;
        if(p[i]) x ^= p[i];
        else {
            p[i] = x;
            break;
        }
    }
}
int main() {
    /*
        假设我们分成两个部分A和B,那么A^B = sum, 我们要使得A+B最大，B可以看成是sum里面分出A集合
        考虑二进制第i位的1的数量为奇数,那么我们不论如何分那么这位的i对于答案是没有影响的,因为要么A1B0,要么B0A1
        所以我们就要考虑第i位的1的数量是偶数的
        首先我们重构a数组,把所有奇数的1都去除(因为不影响结果
        偶数数量的1的位置sum对应的那位二进制肯定是0，那么0的位置如果我们提取出1的话，那么这个位置也变成了1,那么加起来就很nice，
        而且就是要优先保证高位的1被提取出来
        想想新的a数组求最大值子集异或和的过程，就是高位有1的话，并且当前的最大值的这个位置没有1就异或,这样就是相当于提取高位1的过程
    */
    int n; scanf("%d",&n);
    ll sum = 0;
    rep(i, 0, n) scanf("%lld",a+i), sum ^= a[i];
    rep(i, 0, 60) if(sum & (1ll<<i)) {
        rep(j, 0, n) if(a[j] & (1ll<<i)) a[j] ^= (1ll<<i);
    }
    rep(i, 0, n) add(a[i]);
    ll ret = 0;
    repd(i, 60, 0) if(!(ret&(1ll<<i))) ret ^= p[i];
    printf("%lld\n", (sum ^ ret) + ret);
    return 0;
}
