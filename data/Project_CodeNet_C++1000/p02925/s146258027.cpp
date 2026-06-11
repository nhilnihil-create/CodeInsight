#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

int n;

int main() {
    cin >> n;
    vector< vector<int> > Amap(n, vector<int>(n-1, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n-1; ++j) {
            cin >> Amap[i][j];
            Amap[i][j]--;
        }
        reverse(Amap[i].begin(), Amap[i].end());
    }

    vector<P> q;
    auto check = [&](int i) {
        if(Amap[i].size() == 0) return;
        int j = Amap[i].back();     // 対戦相手
        if(Amap[j].size() == 0) return;
        if(Amap[j].back() == i) {
            // 相手の次の対戦相手が自分だった時
            P p(i, j);
            if(p.second < p.first) swap(p.first, p.second);
            q.push_back(p);
        }
    };

    // それぞれの1回戦の相手を突っ込んでみる
    for(int i = 0; i < n; ++i) {
        check(i);
    }

    int day = 0;
    while(q.size() > 0) {
        day++;
        vector<P> prevQ;    // prevQは最初は空でqと入れ替える
        sort(q.begin(), q.end());
        q.erase(unique(q.begin(), q.end()), q.end());   // ユニークな試合だけ残す
        swap(prevQ, q);
        for(auto p : prevQ) {
            // この試合は行われたので消す
            int i = p.first, j = p.second;
            Amap[i].pop_back();
            Amap[j].pop_back();
        }
        for(auto p : prevQ) {
            // 次の試合を確認する
            int i = p.first, j = p.second;
            check(i);
            check(j);
        }
    }
    // 全試合消化できていればクリア
    for(int i = 0; i < n; ++i) {
        if(Amap[i].size() != 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << day << endl;
}