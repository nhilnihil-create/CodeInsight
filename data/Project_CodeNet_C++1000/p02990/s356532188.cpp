#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;


// a^n mod を計算する
long int modpow(long int a, long int n) {
    long int res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    ll n, k;
    cin >> n >> k;
    ll num1, num2;
    num1 = n - k + 1;
    num2 = 1;
    ll ans = num1 * num2;
    cout << ans << endl;
    for (int i = 2; i <= k; i++){
        num1 *= (n - k + 1 - i + 1);
        num1 %= mod;
        num1 *= modpow(i, mod - 2);
        num1 %= mod;
        num2 *= (k - 1 - i + 2);
        num2 %= mod;
        num2 *= modpow(i - 1, mod - 2);
        num2 %= mod;
        ans = (num1 * num2) % mod;
        // cout << num1 << " " << num2 << endl;
        cout << ans << endl;
    }
}