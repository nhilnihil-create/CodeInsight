#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
#include <cfloat>
#include <math.h>
#include <numeric>
#include <string.h>
#include <sys/time.h>
#include <random>


#define fs first
#define sc second

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<ll, ll> P;


// a と b の最大公約数を返す
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}


ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}



// 素数判定
bool is_prime(ll N) {
    if (N == 1) return false;
    for (ll i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}


// 約数列挙
vector<ll> enum_divisors(ll N) {
    vector<ll> res;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            if (N/i != i) res.push_back(N/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}


// 素因数分解
vector<pair<ll, ll>> prime_factorize(ll N){
    vector<pair<ll, ll>> res;
    for(ll i = 2; i * i <= N; i++){
        if(N % i != 0)  continue;
        ll ex = 0;

        while(N % i == 0){
            ex++;
            N /= i;
        }

        res.push_back({i, ex});
    }

    if(N != 1)  res.push_back({N, 1});
    return res;
};


int main(){
    ll n, k;    cin >> n >> k;
    vector<ll> a(n);
    ll su = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        su += a[i];
    }

    vector<ll> divs = enum_divisors(su);

    reverse(divs.begin(), divs.end());
    for(auto d: divs){
        ll sux = 0;
        vector<ll> b;
        for(int i = 0; i < n; i++){
            sux += a[i] % d;
            b.push_back(a[i] % d);
        }
        sort(b.begin(), b.end());
        ll num = n - sux / d;
        ll res = 0;
        for(int i = 0; i < num; i++){
            res += b[i];
        }
        if(res <= k){
            cout << d << endl;
            return 0;
        }
    }



    return 0;
}