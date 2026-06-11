#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;

using namespace std;

int main(){
    int n;  cin >> n;
    ll a, b, c, d;
    a = 1;
    b = 1;
    c = 1;
    d = 1;
    for(int i=1; i<=n; i++){
        a *= 10;
        b *= 9;
        c *= 9;
        d *= 8;
        a %= MOD;
        b %= MOD;
        c %= MOD;
        d %= MOD;
    }
    print((a+d-b-c+MOD+MOD) % MOD);
}