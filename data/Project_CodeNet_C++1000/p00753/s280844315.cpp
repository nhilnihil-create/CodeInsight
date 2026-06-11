#include <bits/stdc++.h>
using namespace std;

#define MAX_SQRT_B 1000005
#define MAX_L 1000005

typedef long long ll;

bool is_prime[MAX_L];
bool is_prime_small[MAX_SQRT_B];

int main(){
    while(1){
        ll n;
        ll p=0;
        scanf("%lld",&n);
        if(n==0){
            break;
        }
        for (int i = 0; (ll)i*i <= 2*n; i++) is_prime_small[i] = true;
        for (int i = 0; i <= n; i++) is_prime[i] = true;

        for(int i= 2; (ll)i*i <= 2*n;i++){
            if(is_prime_small[i]){
                for (int j = 2*i; (ll)j*j <= 2*n ; j+= i) is_prime_small[j] = false;
                for(ll j = max(2LL,(n+i-1)/i)*i;j <= 2*n;j+= i)is_prime[j-n] = false;
            }
        }
        for (ll i = n+1; i <= 2*n; i++){
            if(is_prime[i-n]){
                p++;
            }
        }
        printf("%lld\n",p);

    }

}
