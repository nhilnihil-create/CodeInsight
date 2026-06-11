#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

string S;

int main() {

    // ll c = 0;

    // ll tmp = 5;
    // ll tmp2 = 3;

    // c += tmp * (tmp + 1) / 2;
    // tmp2--;
    // c += tmp2 * (tmp2 + 1) / 2;

    // cout << c << endl;
    // return 0;
    cin >> S;

    // 圧縮
    vector<pair<char, int>> v;

    queue<pair<char, int>> que;
    rep(i, S.size()) {
        // 1こめ
        if (i == 0) {
            que.push(make_pair(S[i], 1));
        } else {
            pair<char, int> q2 = que.front();
            que.pop(); 

            if (q2.first == S[i]) {
                q2.second++;
                que.push(q2);

            } else {
                v.push_back(q2);

                // 新しい文字
                que.push(make_pair(S[i], 1));
            }
        }

        // 最後の1つ
        if (i == S.size() - 1 && que.size() >= 1) {
            v.push_back(que.front());
        }
    }
    // cout << v[0].first << " " << v[0].second << endl;

    // vector<ll> a;
    ll ans = 0;

    bool close = false;
    ll left = 0, right = 0;
    rep(i, v.size()) {
        if (v[i].first == '>') {
            right = v[i].second;
            close = true;
        } else {
            left = v[i].second;

            // open
            close = false;
        }

        if (close) {
            // cout << left << " " << right << endl;
            if (min(right, left) <= 1) {
                ll tmp = max(right, left);
                ans += tmp * (tmp + 1) / 2;
            } else {
                ll tmp = max(right, left);
                ans += tmp * (tmp + 1) / 2;

                ll tmp2 = min(right, left);
                tmp2--;
                ans += tmp2 * (tmp2 + 1) / 2;
            }
        }

        // 最後のケース 開きっぱなしで終わるケース
        if (i == v.size() - 1 && v[v.size() - 1].first == '<') {
            // cout << "last:" << v.size() << " " << v[i].second << endl;
            ll a = v[i].second;
            ans += a * (a + 1) / 2;
        }
    }
    cout << ans << endl;
}