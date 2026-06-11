#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,ll>pa;

const int N=2e5+100;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;

ll qpow(ll x,ll n)
{
    if(x==0&&n==0) return 1;
    ll sum=1;
    while(n){
        if(n&1) {
            sum=sum*x%mod;
        }
        x=x*x%mod;
        n>>=1;
    }
    return sum;
}
ll A[2000010];
ll C(int x,int y)
{
    if(y>x) return 0;
    if(y<0) return 0;
    //if(y==0) return 1;
    return A[x]*qpow(A[y],mod-2)%mod*qpow(A[x-y],mod-2)%mod;
}

void init()
{
    A[0]=1;
    for(int i=1;i<=2e6;i++)
        A[i]=A[i-1]*i%mod;
}
int main()
{
    init();
    int x,y;
    cin>>x>>y;
    if((x+y)%3!=0) {
        cout<<0<<endl;
    }
    else{
        cout<<C((x+y)/3,(2*y-x)/3)<<endl;
    }
}

