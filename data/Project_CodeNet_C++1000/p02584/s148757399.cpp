#include<bits/stdc++.h>
// using namespace std;
typedef long long ll;
const int N=1e2+5;
int l[N];
int main(){
    // ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
    // freopen("a.in","r",stdin);
    // int T;scanf("%d",&T);for(int tttt=1;tttt<=T;tttt++){
    if(true){
    // while(~scanf("%d",&n)){
    ll x,k,d;
    scanf("%lld%lld%lld",&x,&k,&d);
    if(x<0) x=-x;
    __int128 tot=(__int128)k*d;
    if(tot>=x){
        __int128 step=x/d;//正方向步数
        if(step%2^k%2){//不同
            printf("%lld",d-x%d);
        }
        else printf("%lld",x%d);
    }
    else{
        printf("%lld\n",(ll)(x-tot));
    }
    }return 0;
}
