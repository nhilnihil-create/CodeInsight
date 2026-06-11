#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int n;
    cin >> n;
    vector<deque<int>> a(n);
    rep(i,n) {
        rep(j,n-1) {
            int A;
            cin >> A;
            A--;
            a[i].push_back(A);
        }
    }
    vector<P> q;
    auto check = [&](int i) {
        if (a[i].size() == 0) return;
        int j = a[i].front();
        if (a[j].size() == 0) return;
        if (a[j].front() == i) {
            P p(i,j);
            if (p.second < p.first) swap(p.first, p.second);
            q.push_back(p);
        }
    };
    rep(i,n) check(i);
    int day = 0;
    while (q.size() > 0) {
        day++;
        sort(q.begin(), q.end());
        q.erase(unique(q.begin(), q.end()), q.end());
        vector<P> prevQ;
        swap(prevQ, q);
        for (P p : prevQ) {
            int i = p.first, j = p.second;
            a[i].pop_front();
            a[j].pop_front();
        }
        for (P p : prevQ) {
            int i = p.first, j = p.second;
            check(i);
            check(j);
        }
    }
    rep(i,n) {
        if (a[i].size() != 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << day << endl;
    return 0;
}