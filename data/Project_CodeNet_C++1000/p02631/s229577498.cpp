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
int n, sum, a[maxn];

int main()
{
    read(n);
    _rep(i, 1, n) read(a[i]), sum^=a[i];
    _rep(i, 1, n) printf("%d ", sum^a[i]);
    return 0;
}
