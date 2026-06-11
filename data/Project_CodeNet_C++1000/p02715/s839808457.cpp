#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <math.h>

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef vector<ll> vll;

typedef pair<int, int> pii;

typedef queue<int> qi;
typedef queue<string> qs;


#define rep(i, n) for(int i=0; i<(n); ++i)
#define repp(i, a, b) for(int i = (a); i <= (b); i++)
#define repm(i, a, b) for(int i = (a); i >= (b); i--)

#define all(v) v.begin(), v.end()
//sort( all(v) )　などと使える


const ll MOD = pow(10, 9) + 7;

ll mod_pow(ll a, ll b, ll mod){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = res * a % mod;
        a = a*a % mod;

        b >>= 1;
    }
    return res;
}

int main(){
    int n, k;
    cin >> n >> k;


    //gcd = gとなる組合わせの数d[g]を計算する
    ll d[100010];
    //gcd = g <=> gの倍数 - 2*gの倍数 - 3*gの倍数...
    //↓gの倍数
    for(int g = 1; g <= k; g++){
        int m = k/g;
        d[g] = mod_pow(m, n, MOD);
    }
    //↓2*gの倍数,3の倍数,,,をひいてゆく
    for(int g = k; g >= 1; g--){
        for(int gg = 2*g; gg <= k; gg += g){
            d[g] -= d[gg];
            d[g] %= MOD;
        }        
    }


    ll ans = 0;
    for(int g = 1; g <= k; g++){
        ans += d[g] * g;
        ans %= MOD;
    }

    if(ans < 0) ans += MOD;

    cout << ans << endl;
}