#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define fre freopen("C:\\in.txt", "r", stdin)
#define _for(i,a,b) for(int i=a; i< b; i++)
#define _rep(i,a,b) for(int i=a; i<=b; i++)
#define lowbit(a) ((a)&-(a))
#define inf 0x3f3f3f3f
#define endl "\n"
using namespace std;
typedef long long ll;
template <class T>
void read(T &x)
{
    char c; bool op=0;
    while(c=getchar(), c<'0'||c>'9') if(c=='-') op=1;
    x=c-'0';
    while(c=getchar(), c>='0'&&c<='9') x=x*10+c-'0';
    if(op) x=-x;
}

const int maxn=2e5+5;
int n, u[maxn], v[maxn];

int main()
{
    read(n);
    _rep(i, 1, n-1) read(u[i]), read(v[i]);
    _rep(i, 1, n) if(u[i]>v[i]) swap(u[i], v[i]);
    ll ans=0;
    _rep(i, 1, n) ans+=1ll*i*(n-i+1);
    _rep(i, 1, n) ans-=1ll*u[i]*(n-v[i]+1);
    printf("%lld\n", ans);
    return 0;
}
