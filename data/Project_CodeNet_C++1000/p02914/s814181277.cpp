/**
    The problem simply asks you to do the following
    Given array a of n integer
    Divide it into two groups such that
    sum of (xor sum of two groups) is maximized
*/

/**
    overall xor sum is constant
    At first, observe that if the bit of xor sum is 1
    Then, no matter how we divide it
    The result is constant
    So we can simply ignore this
    Solve the rest
    The xor sum of two groups are equal since over all xor sum is 0
    So we can find maximum xor among overall subset
    by the knowledge of basis (Linear algebra!)
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int n;
using ll = long long;
ll basis[65];
ll a[maxn];
void ins(ll x){
    for(int i = 61;i>= 0 ;i--){
        if(!((x>>i) & 1)) continue;
        if(basis[i] == -1)
            return (void)(basis[i] = x);
        x ^= basis[i];
    }
}
bool odd[65];

int main(){
    memset(basis,-1LL,sizeof(basis));
    scanf("%d",&n);
    ll xorsum = 0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        xorsum ^= a[i];
    }
    ll oddsum = 0;
    for(int i=60;i>=0;i--){
        if((xorsum >> i) & 1){
            odd[i] = true;
            oddsum ^= (1LL << i);
        }
    }
    for(int i=60;i>=0;i--){
        if(!odd[i]) continue;
        for(int j=1;j<=n;j++){
            if((a[j] >> i) &1)
                a[j] ^= (1LL << i);
        }
    }
    for(int i=1;i<=n;i++){
        ins(a[i]);
    }
    ll ans = 0;
    for(int i=60;i>=0;i--){
        if( (ans >>i) & 1)continue;
        if(basis[i] != -1) ans ^= basis[i];
    }
    ans <<= 1;
    printf("%lld\n",ans+oddsum);
}
