#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll gcd(ll a, ll b){
    if(a < b) return gcd(b, a);
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll lcm(ll a, ll b){
    ll ret = a / gcd(a,b) * b;
    return ret;
}

int main(){
    ll n, k;
    cin >> n >> k;
    ll ans = min(n % k, k - n % k);
    cout << ans << endl;
    return 0;
}