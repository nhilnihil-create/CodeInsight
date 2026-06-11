#include <bits/stdc++.h>
inline int read(){char c = getchar();int x = 0,s = 1;
while(c < '0' || c > '9') {if(c == '-') s = -1;c = getchar();}
while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}
return x*s;}
using namespace std;
#define NewNode (TreeNode *)malloc(sizeof(TreeNode))
#define Mem(a,b) memset(a,b,sizeof(a))
#define lowbit(x) (x)&(-x)
const int N = 2e5 + 5;
const long long INFINF = 0x7f7f7f7f7f7f7f;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
const int mod = 1e9+7;
const double II = acos(-1);
const double PP = (II*1.0)/(180.00);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> piil;
int n,m,arr[N],Max,ans[N];
int Find(int x)
{
    if(x == arr[x]) return x;
    return arr[x] = Find(arr[x]);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //    freopen("input.txt","r",stdin);
    //    freopen("output.txt","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) arr[i] = i;
    while(m--)
    {
        int a,b;
        cin >> a >> b;
        if(a > b) swap(a,b);
        if(Find(a) != Find(b))
            arr[Find(a)] = arr[Find(b)];
    }
    for(int i = 1;i <= n;i++)
    {
        int x = Find(arr[i]);
        ans[x]++;
        Max = max(Max,ans[x]);
    }
    cout << Max << endl;
}