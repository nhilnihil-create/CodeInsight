#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
char S[20][20];
int D[20][20];

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }

ll calc(ll N){
    ll ans = 0;
    for(int i = 1; i < ll(log10(N)); i++){
        ans += i;
        ans *= 9;
    }
    return ans;
}


int main(){
    ll N,ans = 0;
    cin >> N;
    ll div = 10;
    if(N % 2 == 0){
        while(ll (N / div) >= 1){
            ans += ll (N / div);
            div *= 5;
        }
    }
    else{
        ans = 0;
    }
    cout << ans << endl;
}

