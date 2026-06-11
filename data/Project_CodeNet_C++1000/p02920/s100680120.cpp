#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define iter(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define riter(i, c) for (auto i = (c).rbegin(); i != (c).rend(); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

using P = pair<int, int>;

vector<P> runLength(const vector<int>& s) {
    vector<P> res;
    int now = s[0];
    int cnt = 1;
    rep(i, 1, s.size()) {
        if (now == s[i]) {
            ++cnt;
        }
        else {
            res.emplace_back(now, cnt);
            now = s[i];
            cnt = 1;
        }
    }
    res.emplace_back(now, cnt);
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> S(1 << N);
    for (auto& s : S) {
        cin >> s;
    }
    sort(all(S));
    reverse(all(S));
    vector<P> v = runLength(S);
    int idx = 0;
    priority_queue<int> que;
    que.push(N);
    while (!que.empty()) {
        if (v[idx].second > (int)que.size()) {
            cout << "No" << endl;
            return 0;
        }
        vector<int> hv;
        rep(i, 0, v[idx].second) {
            int h = que.top();
            que.pop();
            rep(hh, 0, h) {
                hv.push_back(hh);
            }
        }
        for (auto& h : hv) {
            que.push(h);
        }
        ++idx;
    }
    cout << "Yes" << endl;
    return 0;
}