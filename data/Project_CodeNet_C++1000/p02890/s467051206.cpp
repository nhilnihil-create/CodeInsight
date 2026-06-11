#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }
template<typename T> inline T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }




int n;
vector<int> nums;
vector<ll> acc;
int k;

bool check(int d) { // d組できますか
    auto it = upper_bound(all(nums), d) - nums.begin();
    it--;
    ll sum;
    if (it < 0) {
        sum = (ll)sz(nums) * d;
    } else {
        sum = acc[it];
        sum += (ll)(sz(nums) - it - 1) * d;
    }
    if (sum >= (ll)k * d) return 1;
    
    return 0;
}

template<typename T>
void binary_search(T ok, T ng) {
    while (abs(ng - ok) > 1) {
        T mid = (ng + ok) / 2;
        (check(mid) ? ok : ng) = mid;
    }
    cout << ok << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    cin >> n;
    map<int, int> mp;
    rep(i, n) {
        int a;
        cin >> a;
        mp[a]++;
    }
    
    for (auto e : mp) nums.eb(e.S);
    sort(all(nums));
    rep(i, sz(nums)) acc.eb(nums[i]);
    rep3(i, 1, sz(nums)) acc[i] += acc[i - 1];
    
    rep3(i, 1, n + 1) {
        k = i;
        binary_search(0, n + 1);
    }
    
    
}
