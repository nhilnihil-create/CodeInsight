#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
//#pragma GCC target ("avx,tune=native")
//Use above if bruteforcing with lots of small operations. Or just use it anytime, there's no downside.
//AVX is better slightly
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef long double ld;

ll inv(ll a, ll b){
    return (a > 1 ? b - inv(b%a, a)*b/a : 1);
}

#define rc(s) return cout << s, 0
#define fi first
#define se second
#define L (nod << 1)
#define R (L | 1)
#define smax(X, Y) ((X) > (Y) ? (X) : (Y))
#define smin(X, Y) ((X) < (Y) ? (X) : (Y))
#define N 100100

const ld e = 2.71828182845904523536028747;
const ld PI = 3.14159265359;
const ll inf = (1LL<<62);
const int iinf = (1<<30);
const int MAX_BIT = 60;
//CLOCKS_PER_SEC

int fv[100], n;
ll basis[100], a[N], temp, ans;

void insertBasis(ll mask){
    for (int i = MAX_BIT - 1; i>=0; i--){
        if (((1LL << i) & mask) == 0) continue;
        if (!basis[i]){
            basis[i] = mask;
            return;
        }
        mask ^= basis[i];
    }
}

int main(){
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //ifstream cin ("test.in");
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++)
        for (int j=0; j<60; j++)
            if ((1LL << j) & a[i]) fv[j]++;
    for (int j=0; j<MAX_BIT; j++){
        if (fv[j] % 2 == 0) continue;
        temp += (1LL << j);
        for (int i=1; i<=n; i++)
            if (a[i] & (1LL << j)) a[i] -= (1LL << j);
    }
    for (int i=1; i<=n; i++) insertBasis(a[i]);
    for (int i=MAX_BIT - 1; i>=0; i--){
        if (!basis[i]) continue;
        if (ans & (1LL << i)) continue;
        ans ^= basis[i];
    }
    ans += ans + temp;
    cout << ans;
    return 0;
}
