#include<stdio.h>
#include<iostream>
#define out(u,v) printf("%d %d\n",u,v)
#define lowbit(x) (x&(-x))
using namespace std;
int n,m,a,b;
int main(){
    // freopen("atcoder5140.in","r",stdin);
    // freopen("atcoder5140.out","w",stdout);
    scanf("%d",&n);
    if(n==lowbit(n)||n<3) return puts("No"),0;
    puts("Yes");
    out(1,2);out(2,3);out(3,n+1);out(n+1,n+2);out(n+2,n+3);
    for(int i=4;i<n;i+=2) out(1,i+1),out(i+1,i),out(1,i+n),out(i+n,i+1+n);
    if(!(n&1)) out(n,lowbit(n)+n),out(n+n,(n^lowbit(n))^1);
    return 0;
}
