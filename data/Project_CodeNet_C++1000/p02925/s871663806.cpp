#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n - 1));
    rep(i, n) {
        rep(j, n - 1) {
            cin >> a[i][j];
            --a[i][j];
        }
        reverse(a[i].begin(), a[i].end());
    }

    vector<pair<int, int>> q;
    auto check = [&](int i) {
        if (a[i].size() == 0) return;
        int j = a[i].back();
        if (a[j].size() == 0) return;
        if (a[j].back() == i) {
            pair<int, int> p(i, j);
            if (p.second < p.first) swap(p.first, p.second);
            q.push_back(p);
        }
    };
    rep(i, n) {
        check(i);
    }
    int day = 0;
    while(q.size() > 0) {
        day++;
        sort(q.begin(), q.end());
        q.erase(unique(q.begin(), q.end()), q.end());
        vector<pair<int, int>> prevQ;
        swap(prevQ, q);
        for (pair<int, int> p : prevQ) {
            int i = p.first;
            int j = p.second;
            a[i].pop_back();
            a[j].pop_back();
        }
        for (pair<int, int> p : prevQ) {
            int i = p.first;
            int j = p.second;
            check(i);
            check(j);
        }
    }

    rep(i, n) {
        if (a[i].size() != 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << day << endl;

    return 0;
}