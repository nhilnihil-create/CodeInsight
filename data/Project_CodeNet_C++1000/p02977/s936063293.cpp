#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
using namespace std;
int n,k;
void ot(int u,int v){printf("%d %d\n",u,v);;}
int main(){
    scanf("%d",&n);while((1<<k+1)<=n) ++k;
    int m=1<<k;if(m==n) return puts("No"),0;puts("Yes");
    ot(1,3);ot(3,2);ot(2,n+1);ot(n+1,n+3);ot(n+3,n+2);
    rep(i,2,(n-1)/2) ot(1,2*i),ot(1,2*i+1),ot(2*i,2*i+1+n),ot(2*i+1,2*i+n);
    if(!(n&1)){
        int t=m^1^n;
        ot(m,n),ot(t,2*n);
    }
    return 0;
}