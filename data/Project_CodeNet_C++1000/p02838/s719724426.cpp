#include <numeric>
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <math.h> 
#include <set>
#include <map>
#include <utility>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

#define ll long long int
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repp(i, n) for(ll i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define riverse(v) reverse((v).begin(), (v).end())
#define pb push_back
#define mp make_pair
#define all(a)  (a).begin(),(a).end()
using vi = vector<int>;
using vs = vector<string>;
using vc = vector<char>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vb = vector<bool>;
using vvb = vector<vb>;
const ll MOD = 1e9 + 7;
set<char> alphabet = { 'a','b','c','d','e','f','g','h','i','j','k','l','m',
               'n','o','p','q','r','s','t','u','v','w','x','y','z' };

int main() {
    ll N;
    cin >> N;
    ll ans = 0;
    vll A(N);
    rep(i, N) cin >> A[i];
    vector<vll>  B(61, vll(2,0));
    rep(i, 61) {
        rep(j, N) {
            if (A[j] % 2 == 1) B[i][1]++;
            else B[i][0]++;
            A[j] /= 2;
        }
    }
    rep(i, 61) {
        ll a = B[i][0] * B[i][1];
        a = a % MOD;
        ll j = 1;
        while (j <= i) {
            a = 2 * a;
            a = a % MOD;
            j++;
        }
        ans += a;
        ans %= MOD;
    }
    cout << ans << endl;
}