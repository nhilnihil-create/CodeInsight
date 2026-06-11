#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    ll N, K , S;
    cin >> N >> K >> S;

    if(S == 1000000000){
        for (ll i = 0; i < K; i++) {
            printf("%lld ", S);
        }   
        for (ll i = K; i < N; i++) {
            printf("1 ");
        }
    }
    else{
        for (ll i = 0; i < K; i++) {
            printf("%lld ", S);
        }   
        for (ll i = K; i < N; i++) {
            printf("1000000000 ");
        }
    }


}