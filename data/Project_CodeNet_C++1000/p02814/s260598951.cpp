#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll gcd(ll a,ll b)
{
	return b==0?a:gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
	return a*b/gcd(a,b);
}
ll a[100006];
int main(){
    ll n,m;
    scanf("%lld%lld",&n,&m);
    int lcm1=1;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(lcm1>m){
            continue;
        }
        lcm1=lcm(lcm1,a[i]/2);
    }
    if(lcm1>m){cout<<0<<'\n';return 0;}
    int flag=0;
    for(int i=1;i<=n;i++){
        int temp=lcm1*2/a[i];
        if(temp%2==0){
            flag=1;
            break;
        }
    }
    if(flag){
        puts("0");
        return 0;
    }
    int cnt=m/lcm1;
    if(cnt&1){
        cnt=cnt/2+1;
    }
    else{
        cnt=cnt/2;
    }
    printf("%lld\n",cnt);
    return 0;
}