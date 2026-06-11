#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const int INF = 1e9 + 6;
const int MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()

int main() {
    string s, t; cin >> s >> t;
    vector<vector<int>> posS(26);
    rep(i, s.size()) {
        posS[s[i] - 'a'].pb(i);
    }
    rep(i, t.size()) {
        if(posS[t[i] - 'a'].empty()) {
            cout << -1 << endl;
            return 0;
        }
    }
    ll ans = posS[t[0] - 'a'][0] + 1;
    int tmppos = posS[t[0] - 'a'][0];
    rep(i, t.size() - 1) {
        //二分探索してくださいね upper_boundね それが==posS[t[i + 1] - 'a'].size()ならもう一週ですよ
        int key = upper_bound(all(posS[t[i + 1] - 'a']), tmppos) - posS[t[i + 1] - 'a'].begin();
        if(key == posS[t[i + 1] - 'a'].size()) {
            ans += (s.size() - tmppos - 1);
            tmppos = posS[t[i + 1] - 'a'][0];
            ans += (tmppos + 1);
        }else {
            ans += (posS[t[i + 1] - 'a'][key] - tmppos);
            tmppos = posS[t[i + 1] - 'a'][key];
        }
    }
    cout << ans << endl;
}
