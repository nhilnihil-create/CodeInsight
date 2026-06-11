#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
template<class _T>inline void read(_T &_a)
{
    bool f=0; char _c=getchar(); _a=0;
    while(_c<'0'||_c>'9'){ if(_c=='-') f=1; _c=getchar(); }
    while(_c>='0'&&_c<='9'){ _a=(_a<<3)+(_a<<1)-'0'+_c; _c=getchar(); }
    if(f) _a=-_a;
}

const int MAXN = 100002;
int n, a[MAXN], ans[MAXN];

int main()
{
    read(n);
    for (int i = 1; i <= n; ++i) read(a[i]);
    for (int i = 1; i <= n; ++i)
        ans[1] += a[i] * pow(-1, i + 1);
    for (int i = 2; i <= n; ++i)
        ans[i] = 2 * a[i - 1] - ans[i - 1];
    for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
    return 0;
}