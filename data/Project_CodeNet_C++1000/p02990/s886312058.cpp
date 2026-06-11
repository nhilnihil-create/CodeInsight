#include <iostream>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <cstdio>
#include <math.h>
#include <map>
#include <algorithm>
#include <deque>
#include <stack>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int>pa;
const int N =2e5+100;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const int modd=1e9+5;

ll a[2010];
void jc()
{
    a[0]=a[1]=1;
    for(int i=2;i<=2000;i++)
        a[i]=a[i-1]*i%mod;
}
ll ksm(ll x,ll y)
{
     if(x==0) return 0;
     ll sum=1;
     while(y){
        if(y&1) sum=sum*x%mod;
        x=x*x%mod;
        y>>=1;
     }
     return sum;
}
long long C(int n,int m)
{
    if(m>n) return 0;
    if(m==n) return 1;
    ll result;
    result=(a[n]*ksm(a[n-m],modd)%mod)*ksm(a[m],modd)%mod;
    return result;
}
int main()
{
    int n,k;
    jc();
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++){
        //ll ans1=(a[k-1]*ksm(a[i-1],modd)%mod)*ksm(a[k-i-1],modd)%mod;
       // ll ans2=(a[n-k+1]*ksm(a[i],modd)%mod)*ksm(n-k+1-i,modd)%mod;
       // ans1=ans1*ans2%mod;
       ll ans=C(n-k+1,i)*C(k-1,i-1)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}

