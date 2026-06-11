/// You just can't beat the person who never gives up
/// ICPC next year

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+5 ,mod = 1e9+7 ;

int n ,k ,cnt[N] ,ans ;
int pwr(int b,int p){
    int res=1;
    while(p){
        if(p%2) res = 1ll*res*b%mod;
        b = 1ll*b*b%mod;
        p/=2;
    }
    return res;
}
bool Never_give_up(){
    cin >> n >> k ;
    for(int i=k;i>=1;--i){
        cnt[i] = pwr(k/i,n) ;
        for(int j=i+i;j<=k;j+=i) cnt[i] = ((cnt[i] - cnt[j])%mod + mod)%mod ;
        ans = (0ll + ans + 1ll * cnt[i]*i%mod) %mod ;
    }
    cout << ans ;
    return 0;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" ,"r" ,stdin);
    freopen("output.txt" ,"w" ,stdout);
#endif
    std::ios::sync_with_stdio(0);
    cin.tie(0) ,cout.tie(0);
    int t = 1 ;
    //cin >> t ;
    while(t--){
        Never_give_up();
    }
    return 0;
}