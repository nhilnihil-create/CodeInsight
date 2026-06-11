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
string s, t;
int main()
{
    syio;
    cin>>s>>t;
    int mi = inf;
    for (int i = 0; i <= s.size() - t.size(); ++ i)
    {
        int cnt = 0;
        for (int j = 0, k = i; j < t.size(); ++ j, ++ k)
        if (s[k] != t[j]) cnt ++;
        mi = min(mi, cnt);
    }
    cout<<mi<<endl;
    return 0;
}
