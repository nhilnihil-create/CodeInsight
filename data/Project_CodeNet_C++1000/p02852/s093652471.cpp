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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    string s;
    cin >> n >> m >> s;
    reverse(ALL(s));
    int now = 0;
    vector<int> ans;
    while(now < n) {
        bool flg = false;
        for(int i = m; i >= 1; i--) {
            if(now + i <= n && s[now + i] == '0') {
                now += i;
                ans.push_back(i);
                flg = true;
                break;
            }
        }
        if(flg == false) {
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(ALL(ans));
    for(int i : ans) {
        cout << i << ' ';
    }
    cout << endl;
}