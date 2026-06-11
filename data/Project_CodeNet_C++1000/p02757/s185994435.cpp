/// You just can't beat the person who never gives up
/// ICPC next year

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std ;
const int N = 1e6+5 ;

int n ,p ;
string str ;
int cnt[N] ,cur[N] ,len[N] ;
int main(){
    cin >> n >> p >> str ;
    if(p==2 || p==5){
        long long ans = 0 ;
        for(int i=0;i<n;++i) if((str[i]-'0')%p == 0) ans += i+1 ;
        printf("%lld",ans);
        return 0;
    }

    len[0] = 1 ;
    for(int i=1;i<=n;++i) len[i] = len[i-1]*10%p;
    /// arr[i][j] = (arr[i][n] - arr[j+1][n]) / (10^(n-j))
    cnt[0] = 1 ;
    long long ans = 0 ;
    for(int i=n-1;i>=0;--i){
        cur[i] = (len[n-i-1]*(str[i]-'0')%p + cur[i+1])%p ;
        ans += cnt[cur[i]]++ ;
    }
    printf("%lld\n",ans);
    return 0;
}
