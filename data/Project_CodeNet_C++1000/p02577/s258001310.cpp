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
const int mxn = 100033;
inline int read(){
    int x = 0,f = 1;char c = getchar();
    while(!isdigit(c))f = c == '-' ? -1 : 1,c = getchar();
    while(isdigit(c))x = x * 10 + c - '0',c = getchar();
    return x * f;
}
int main()
{
    syio;
    string s;
    cin>>s;
    int res = 0;
    for (int i = 0; i < s.size(); ++ i)
    res += s[i] - '0';
    if (res % 9 == 0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
