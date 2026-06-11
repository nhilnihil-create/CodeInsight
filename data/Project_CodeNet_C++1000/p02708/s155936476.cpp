#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isprime(int n){
    double rootn = sqrt(n);
    if (n < 2){
        return false;
    }
    else if (n == 2){
        return true;
    }
    else if (n % 2 == 0){
        return false;
    }
    else{
        for(int i = 3; i <= rootn; i += 2){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
}


int main(){
    ll N, K;
    ll mod = 1000000007;
    cin >> N >> K;
    ll ans = (((N+1)*(N+K)*(N-K+1)/2 - (N*(N+1)*(2*N+1)/6-(K-1)*K*(2*K-1)/6))%mod + N-K+2)%mod;
    cout << ans << endl;
    return 0;
}