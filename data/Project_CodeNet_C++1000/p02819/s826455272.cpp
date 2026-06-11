#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;

bool prime_factorize(int x){
    if(x == 1) return false;
    for(int i = 2;i * i <= x;i++){
        if(x % i == 0) return false;
    }
    return true;
}

int main() {
    int x; cin >> x;
    while(true){
        if(prime_factorize(x)){
            cout << x << endl;
            break;
        }
        x++;
    }
}
