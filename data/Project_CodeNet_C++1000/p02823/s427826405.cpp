#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <cctype>
#include <map>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <queue>


#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;

bool is_integer( float x ){
    return floor(x)==x;
}

bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

//yakusuu rekkyo
vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // push its partner
            if (N/i != i) res.push_back(N/i);
        }
    }

    sort(res.begin(), res.end());
    return res;
}


vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // exponential

        // divide as much as you can
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // push the result
        res.push_back({a, ex});
    }

    // last num (if the lasting n is prime number and not 1)
    if (N != 1) res.push_back({N, 1});
    return res;
}



int main() {
    ll n,a,b;cin>>n>>a>>b;
    ll t = abs(a-b)-1;
    ll ans = 0;
   
    if(t == -1) cout << 0;
    else {
        if (t % 2 == 1) {
            ans = 1 + (t - 1) / 2;
        } else {
            ll l, r;
            if (a > b) {
                l = b;
                r = a;
            } else {
                l = a;
                r = b;
            }
            if(t == 0) {

                if (r - 1 > n - l) ans = n - l;
                else ans = r - 1;
            }else{
                if (l - 1 < n - r) {
                    ans = (r-l-1)/2+1+l-1;
                }else{
                    ans = (r-l-1)/2+1+n-r;
                }
            }
        }
        cout << ans;
    }

    return 0;
}









