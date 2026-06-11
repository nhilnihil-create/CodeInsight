#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
long long x,k,d;
int fzx_abs(int x) {
        return x<0 ? -x : x;
}
int fzx_min(int x,int y) {
        return x>y ? y : x;
}
signed main()
{
        scanf("%lld %lld %lld",&x,&k,&d);
        x=fzx_abs(x);
        int kk=fzx_min(x/d,k);
        k-=kk;
        x-=kk*d;
        if (k>0 && k&1) x=fzx_min(fzx_abs(x-d),fzx_abs(x+d));
        cout<<x<<"\n";
        return 0;
}
