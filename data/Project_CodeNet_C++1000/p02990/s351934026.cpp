#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <map>
#include<unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include<bitset>
#include<deque>
#include<string>
#include<list>
#include<iterator>
#include<sstream>
#include <algorithm>
#include <numeric>
#include <math.h>

#define user spaesk
#define pi acos(-1)
#define lli long long int
#define ld long double
#define ff first
#define ss second
#define lower(a) transform(a.begin(),a.end(),a.begin(),::tolower);

using namespace std;

typedef vector<vector<lli> > matrix ;

const int N = 3e5 + 500;
const long long mod = 1e9 + 7;
const long long cmod = 998244353 ;
const long long inf = 1LL << 61;
const int M = 1e6 + 500;
const lli ths = 1LL << 40;
const int NN = 5e3 + 6;

lli modexp(lli a, lli n) {

    lli r = 1;
    while(n) {
        if(n & 1) {
            r = (r * a) % mod;
        }
        a = (a * a) % mod;
        n >>= 1;
    }

    return r;

}

void solve()
{

    lli n, k;
    cin>>n>>k;

    lli fact[2007] = {};

    fact[1] = 1;
    fact[0] = 1;
    for(int i = 2; i <= n; i ++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }

    for(int i = 1; i <= k; i ++) {
        lli X = n - k + 1;
//        cout<<"DSD"<<endl;
        lli ans = fact[X];
        if(X < i) {
            ans = 0;
        }
//        cout<<ans<<endl;
        lli t = modexp(fact[i], mod - 2);
        ans *= t;
        ans %= mod;
        t = modexp(fact[X - i], mod - 2);
        ans *= t;
        ans %= mod;
        lli mul = fact[k - 1] * modexp(fact[i - 1], mod - 2);
        mul %= mod;
        mul = (mul* modexp(fact[k - i], mod - 2)) % mod ;
//        cout<<mul<<endl;
        ans = (ans * mul) % mod;
        cout<<ans<<endl;
    }

    cout<<"\n";
    return ;
}

/*
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
//    cin>>t;
    while(t --)
    {
        solve();
    }
    return 0;
}
