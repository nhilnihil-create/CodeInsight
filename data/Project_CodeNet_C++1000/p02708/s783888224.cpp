//#pragma GCC optimize ('O3')
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 1e5 + 5;
const int M = 1560 + 5;
const ll OO = 2e18;
const int mod = 1e9 + 7;

int n,k,ans;

int cum(int x) {

    return (1LL*x*(x+1)/2)%mod;

}

int add(int a, int b) {

    return (a+b)%mod;

}

int sub(int a, int b) {

    return (a-b+mod)%mod;

}

int mul(int a, int b) {

    return (1LL*a*b)%mod;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for (int i = k; i <= n+1; ++i) {
        int mn = cum(i-1);
        int mx = sub(cum(n), (i==n+1 ? 0 : cum(n-i)));
        ans = add(ans, add(sub(mx,mn),1));
    }

    cout << ans << '\n';

    return 0;
}