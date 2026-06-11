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

const int MAXN=2002;
int n,l[MAXN],ans;

int main()
{
    read(n);
    for (int i=1;i<=n;++i) read(l[i]);
    sort(l+1,l+n+1);
    for (int i=1;i<n-1;++i)
        for (int j=i+1;j<n;++j)
        {
            int sum=l[i]+l[j];
            ans+=lower_bound(l+j+1,l+n+1,sum)-l-j-1;
            //printf("%d %d %d  -  %d\n",i,j,lower_bound(l+j+1,l+n+1,sum)-l,ans);
        }
    printf("%d",ans);
    return 0;
}