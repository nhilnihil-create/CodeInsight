#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans;
    vector<P> op;
    sort(ALL(a));
    
    // 全て正
    if(a[0] >= 0) {
        if(n == 2){
            cout << a[1] - a[0] << endl;
            cout << a[1] << ' ' << a[0] << endl;
            return 0;
        }
        ans = a[0] - a[1];
        op.push_back(P(a[0], a[1]));
        for(int i = 2; i < n - 1; i++) {
            op.push_back(P(ans, a[i]));
            ans -= a[i];
        }
        op.push_back(P(a[n - 1], ans));
        ans = a[n - 1] - ans;
        cout << ans << endl;
        for(auto i : op) {
            cout << i.first << ' ' << i.second << endl;
        }
        return 0;
    }
    // 全て負
    if(a[n - 1] <= 0) {
        sort(RALL(a));
        ans = a[0] - a[1];
        op.push_back(P(a[0], a[1]));
        for(int i = 2; i < n; i++) {
            op.push_back(P(ans, a[i]));
            ans = ans - a[i];
        }
        cout << ans << endl;
        for(auto i : op) {
            cout << i.first << ' ' << i.second << endl;
        }
        return 0;
    }
    // 正と負両方ある
    vector<int> sei, hu;
    for(int i = 0; i < n; i++) {
        if(a[i] >= 0) {
            sei.push_back(a[i]);
        } else {
            hu.push_back(a[i]);
        }
    }
    sort(ALL(sei));
    sort(ALL(hu));

    for(int i = 1; i < sei.size(); i++) {
        op.push_back(P(hu[0], sei[i]));
        hu[0] -= sei[i];
    }
    ans = sei[0];
    for(int i = 0; i < hu.size(); i++) {
        op.push_back(P(ans, hu[i]));
        ans -= hu[i];
    }
    cout << ans << endl;
    for(auto i : op) {
        cout << i.first << ' ' << i.second << endl;
    }

    return 0;
}