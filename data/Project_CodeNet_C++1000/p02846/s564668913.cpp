/*author:revolIA*/
/*明日を変えるなら今日変えなきゃ*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+7,mod = 1e9+7;
ll T1,T2;
ll A1,A2,B1,B2;
int main(){
    scanf("%lld%lld",&T1,&T2);
    scanf("%lld%lld",&A1,&A2);
    scanf("%lld%lld",&B1,&B2);
    A1 *= T1,A2 *= T2;
    B1 *= T1,B2 *= T2;
    ll delt1 = A1-B1;
    ll delt2 = A2-B2;
    if(delt1<0)delt1 *= -1,delt2 *= -1;
    ll delt = delt1+delt2;
    if(delt == 0)return 0*printf("infinity\n");
    if(delt > 0){
        printf("0\n");
    }else{
        ll ans;
        ans = (delt1/(-delt))*2+1;
        if(delt1%(-delt)==0)
            ans --;
        printf("%lld\n",ans);
    }
    return 0;
}
