#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mes(a,b) memset((a),(b),sizeof((a)))
#define syio std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
#define lson l, mid, rt << 1
#define rson mid+1, r, rt << 1 | 1
typedef long long ll;
typedef long double real;
typedef pair<int, int> pii;

const int oo = ~0u >> 2;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int mxn = 200033;
inline int read(){
    int x = 0,f = 1;char c = getchar();
    while(!isdigit(c))f = c == '-' ? -1 : 1,c = getchar();
    while(isdigit(c))x = x * 10 + c - '0',c = getchar();
    return x * f;
}
int n, m, f[mxn], cnt[mxn];
void init()
{
    for (int i = 1; i <= n; ++ i)
    f[i] = i, cnt[i] = 1;
}
int find(int x)
{
    return f[x] == x ? x : f[x] = find(f[x]);
}
void join(int u, int v)
{
    int fu = find(u), fv = find(v);
    if (fu != fv)
    {
        f[fu] = f[fv]; 
        cnt[fv] += cnt[fu];
    }
}
int main()
{
    syio;
    cin>>n>>m;
    init();
    int a, b;
    while (m --)
    {
        cin>>a>>b;
        join(a, b);
    }
    int mx = 0;
    for (int i = 1; i <= n; ++ i)
    if (find(i) == i) mx = max(mx, cnt[i]);
    cout<<mx<<endl;
    return 0;
}
