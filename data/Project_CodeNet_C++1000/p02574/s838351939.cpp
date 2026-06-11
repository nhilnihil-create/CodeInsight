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
const int mxn = 1000003;
inline int read(){
    int x = 0,f = 1;char c = getchar();
    while(!isdigit(c))f = c == '-' ? -1 : 1,c = getchar();
    while(isdigit(c))x = x * 10 + c - '0',c = getchar();
    return x * f;
}
int n, a[mxn];
map<int, int> ct;
vector<int> v[mxn];
bool isnp[mxn];
void init()
{
    isnp[0] = isnp[1] = 1;
    for (int i = 2; i < mxn; ++ i)
    {
        if (isnp[i]) continue;
        v[i].push_back(i);
        for (int j = 2*i; j < mxn; j += i)
        {
            isnp[j] = 1;
            v[j].push_back(i);
        }
    }
}
int main()
{
    syio;
    cin>>n;
    for (int i = 1; i <= n; ++ i) cin>>a[i];
    int f1 = 0, f2 = 0;
    int gd = a[1];
    for (int i = 2; i <= n; ++ i) gd = __gcd(gd, a[i]);
    if (gd == 1) f2 = 1;
    init();
    for (int i = 1; i <= n && !f1; ++ i)
    {
        for (auto it : v[a[i]])
        {
            ct[it] ++;
            if (ct[it] != 1) {f1 = 1; break;}
        }
    }
    if (!f1) cout<<"pairwise coprime"<<endl;
    else if (f2) cout<<"setwise coprime"<<endl;
    else cout<<"not coprime"<<endl;
    return 0;
}