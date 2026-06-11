#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

typedef long long ll;
const int mod = 1e9+7;

ll fast_pow(ll m,ll n){
    ll base = m;
    ll ret = 1;
    while(n){
        if(n&1){
            ret = ret * base % mod; 
        }
        base = base * base %mod;    
        n = n >> 1;
    }
    return ret;
}
//A(N,2) 10^(N-2)
// = N*(N-1) * pow(10,N-2)
int main(){
    ll N;
    cin>>N;
    if(N < 2){
        cout<<0<<endl;
        return 0;
    }
    ll p = N * (N-1) % mod;
    p = fast_pow(10,N) - 2 * fast_pow(9,N) + fast_pow(8,N);
    p = p %mod; 
    if(p < 0){
        p = p + mod;
    }
    cout<<p<<endl;
    
    return 0;
}

