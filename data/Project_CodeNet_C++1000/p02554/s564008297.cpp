#include <iostream>
#include<algorithm>
using namespace std;

typedef long long ll;


const int MOD = 1e9 + 7;
const int N = 2e5 + 105;

ll qpower(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1) ans = ans * a %MOD;
        a = a * a %MOD;
        b >>= 1;
    }
    return ans;
}
int main(){
    ll n;
    cin >> n;
    if(n == 1){
        cout << 0 << endl;
    }else{
        cout << (qpower(10, n) - (qpower(9, n) + qpower(9, n) - qpower(8, n)) + MOD + MOD + MOD + MOD + MOD) % MOD << endl;
    }
}
