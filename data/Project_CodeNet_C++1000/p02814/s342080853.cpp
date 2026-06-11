#include<iostream>
#include<cstring>
#include<algorithm>
typedef long long ll;
using namespace std;
const int maxn=1e5+10;
ll s[maxn];
int main(){
    ll n,m;
    scanf("%lld%lld",&n,&m);
    ll lcm=1;
    for(int i=1;i<=n;i++){
        scanf("%lld",&s[i]);
        if(s[i]%2==0){
            s[i]=s[i]/2;
        }
        lcm=lcm*s[i]/__gcd(lcm,s[i]);
    }
    ll c=0,a,b;
    for(int i=1;i<=n;i++){
        int a=lcm/s[i];
        if(a%2==0){
            c=1;
            break;
        }
    }
    if(c&1){
        cout<<"0"<<endl;
    }
    else
    {
    b=m/lcm;
    if(b&1){
        b=b/2+1;
    }
    else{
        b=b/2;
    }
    printf("%lld\n",b);	
	}
    return 0;
}