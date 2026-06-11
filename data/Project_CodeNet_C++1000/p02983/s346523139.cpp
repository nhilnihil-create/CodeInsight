/*Allah Vorosha*/
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define n_p next_permutation
#define p_p prev_permutation
#define in insert
#define rev reverse
#define pf push_front
#define pob pop_back
#define uniq(v)         v.resize(distance(v.begin(),unique(v.begin(),v.end())))
#define all(x) (x).begin(),(x).end()
#define pof pop_front
#define ios ios_base::sync_with_stdio(0);cin.tie();cout.tie();
#define scn scanf
#define prt printf
#define rep(i, a, n) for(int i = a; i < n; i++)
#define mod 1000000007
#define yes cout << "YES\n"
#define no cout << "NO\n";
#define take for(auto &it : a) cin >> it;
#define out cout << a << "\n";
#define l_b lower_bound
#define u_b upper_bound
#define Max 100005
template<typename T> T mymax(T x, T y) {
    return (x > y ? x : y);
}

using namespace std;

const int N = 2e5 + 5;

void solve() {
    long long x, l;
    cin >> x >> l;
    ll m = x / 2019;
    ll k = (m + 1) * 2019;
    //cout << k;
    if(x % 2019 == 0 || k <= l) {
        //yes;
        cout << 0 << '\n'; return;
    }
    ll ans = 1e8;
    for(ll i = x; i < l; i++) {
        for(ll j = i + 1; j <= l; j++) {
            ll prod = ((i % 2019) * (j % 2019)) % 2019;
            ans = min(ans, prod);
        }
    }
    cout << ans;
}

int main() {

    solve();
    return 0;
}
