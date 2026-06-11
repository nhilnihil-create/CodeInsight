#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long int ll;
const int N_MAX = 200005;
const int P_MAX = 10005;
long long int modp[P_MAX];

ll mod_pow(ll x, ll n, int mod){
    int res = 1;
    while(n > 0){
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    int n, p;
    string S;
    cin >> n >> p >> S;
    ll m = 0;
    long long int ans = 0;
    memset(modp, 0, sizeof(modp));
    modp[0]++;
    if (p == 2){
        for(int i = 0; i < n; i++){
            if ((S[n-1-i] - '0') % 2 == 0){
                ans += n-i;
            }
        }
    }
    else if (p == 5){
        for(int i = 0; i < n; i++){
            if ((S[n-1-i] - '0') % 5 == 0){
                ans += n-i;
            }
        }
    }
    else {
        for(int i = 0; i < n; i++){
            m += mod_pow(10, i, p) * (S[n-1-i] - '0');
            m %= p;
            ans += modp[m];
            modp[m]++;
        }
    }
    cout << ans << endl;
    return 0;
}