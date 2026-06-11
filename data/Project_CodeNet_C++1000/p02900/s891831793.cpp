/*
    Created by Tejas Chaudhari
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef double lf;
typedef bool bl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<lf> vd;
typedef vector<bl> vb;
typedef string st;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

#define INF (LONG_LONG_MAX / 4)
#define SORT(x) sort(x.begin(), x.end())
#define Mod % 1000000007
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second
#define pb push_back

void re_curse() {
    ll a, b;
    cin>>a>>b;
    vb arr(10000000, true);
    for (ll i = 2; i < 10000000; ++i) {
        for (ll j = i*i; j < 10000000; j += i) {
            arr[j] = false;
        }
    }
    vl primes;
    for (int i = 2; i < 10000000; ++i) {
        if (arr[i]) {
            primes.pb(i);
        }
    }
    ll ans = 0;
    for (auto i : primes) {
        if (!(a % i) && !(b % i)) {
            ++ans;
        }
        while (!(a % i)) {
            a = a/i;
        }
        while (!(b % i)) {
            b= b/i;
        }
        if (a == 1 || b == 1) {
            break;
        }
    }
    if (a == b && a != 1) {
        ++ans;
    }
    ++ans;
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    for (int i = 1; i <= t; ++i) {
        re_curse();
    }
    return 0;
}
