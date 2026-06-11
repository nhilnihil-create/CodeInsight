#include <bits/stdc++.h>
#define int long long
using namespace std;
 
const int maxn=1e5+10;
int a[maxn];
signed main(){
    int n,m;
    scanf("%lld%lld",&n,&m);
    int lcm=1;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(lcm>m){
            continue;
        }
        lcm=lcm*a[i]/2/__gcd(lcm,a[i]/2);
    }
    //printf("debug %lld\n",lcm);
    int flag=0;
    for(int i=1;i<=n;i++){
        int temp=lcm*2/a[i];
        if(temp%2==0){
            flag=1;
            break;
        }
    }
    if(flag){
        puts("0");
        return 0;
    }
    int cnt=m/lcm;
    if(cnt&1){
        cnt=cnt/2+1;
    }
    else{
        cnt=cnt/2;
    }
    printf("%lld\n",cnt);
    return 0;
}