//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 2000 + 5;
const int M = 101;
const int Q = 2e5 + 5;
const int OO = 2e9;
const int mod = 1e9 + 7;

int n,k,fact[N];

int prod(int a, int b) {

    return (1LL*a*b)%mod;

}

int fp(int b, int p) {

    if(!p) return 1;

    int res = fp(b,p>>1);

    return prod(prod(res,res),(p&1 ? b : 1));

}

int inv(int a) {

    return fp(a, mod-2);

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    fact[0] = 1;

    for (int i = 1; i < N; ++i)
        fact[i] = prod(fact[i-1],i);

    for (int i = 1; i <= k; ++i) {
        if(i>n-k+1) cout << "0\n";
        else {

            int c1 = prod(fact[k-1],prod(inv(fact[k-i]),inv(fact[i-1])));
            int c2 = prod(fact[n-k+1],prod(inv(fact[n-k-i+1]),inv(fact[i])));
            cout << prod(c1,c2) << '\n';

        }
    }

    return 0;
}