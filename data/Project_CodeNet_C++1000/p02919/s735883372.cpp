#include<bits/stdc++.h>
using namespace std;
#define pb push_back
// #define int long long
typedef long long ll;
#define fi first
#define se second
#define pii pair<ll,int>
#define endl '\n'
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define sz(s) (int)s.size()
#define y1 fdfbvfds
typedef long double f80;
#define all(x) x.begin(), x.end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l,ll r){
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}

const int mod = 998244353;
int pwr(int a,int b) {
    int ans = 1;
    while(b) {
        if(b & 1) {
            ans = (ans * 1LL * a) % mod;
        }
        a = (a * 1LL * a) % mod;
        b >>= 1;
    }
    return ans;
}

const int N = 1e5 + 5;
int a[N];
pii b[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    fr(i, 1, n) {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(b + 1, b + n + 1);
    reverse(b + 1, b + n + 1);
    set<int> s;
    ll ans = 0;
    fr(i, 1, n) {
        auto it = s.upper_bound(b[i].se);
        int lol[4] = {0, 0, 0, 0};
        if(it != s.end()) {
            lol[2] = (*it) - b[i].se;
            auto it1 = it;
            it1++;
            if(it1 != s.end()) {
                lol[3] = (*it1) - (*it);
            }
            else {
                lol[3] = n + 1 - (*it);
            }
        }
        else {
            lol[2] = n + 1 - b[i].se;
        }
        if(it != s.begin()) {
            it--;
            lol[1] = b[i].se - (*it);
            if(it != s.begin()) {
                auto it1 = it;
                it1--;
                lol[0] = (*it) - (*it1);
            }
            else {
                lol[0] = (*it);
            }
        }
        else {
            lol[1] = b[i].se;
        }
        // cout << lol[0] << " " << lol[1] << " " << lol[2] << " " << lol[3] << endl;
        ans += b[i].fi * 1LL * lol[0] * 1LL * lol[2];
        ans += b[i].fi * 1LL * lol[1] * 1LL * lol[3];
        s.insert(b[i].se);
    }
    cout << ans;
    return 0;
}