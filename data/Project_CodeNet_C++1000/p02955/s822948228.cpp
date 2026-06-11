/// However long the night,
///     The dawn will break
/// ICPC next year

#pragma gcc optimize("03")
#include<bits/stdc++.h>
using namespace std ;
const int N = 5e2+5 ;

int n ,k ,a[N] ;
long long sum ,cur[N] ;
bool ok(long long x){
    vector<long long> v ;
    for(int i=0;i<n;++i) v.push_back(a[i]%x);
    sort(v.begin(),v.end());
    for(int i=n-1;i>=0;--i) cur[i] = cur[i+1] + x - v[i] ;
    long long cur1=0 ;
    for(int i=0;i<n;++i){
        cur1 += v[i] ;
        if(cur1!=cur[i+1]) continue ;
        if(cur1<=k) return 1;
    }
    return 0;
}
int main(){
    cin >> n >> k ;
    long long ans = 0  ;
    for(int i=0;i<n;++i){
        cin >> a[i] ;
        sum += a[i] ;
        ans = __gcd(ans,1ll*a[i]);
    }
    for(long long i=1;i*i<=sum;++i){
        if(sum%i) continue ;
        if(ok(i)) ans = max(ans,i);
        if(ok(sum/i)) ans = max(ans,sum/i);
    }
    cout << ans ;
    return 0;
}
