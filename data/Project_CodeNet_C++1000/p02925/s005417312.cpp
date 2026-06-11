#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i ++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> pll;
const ll MOD = 1e9 + 7;
const ll INF = 1e10;

int main() {
    int n; cin >> n;
    vector<vector<int>> a(n,vector<int>(n - 1));
    rep(i,n)rep(j,n - 1) {
        cin >> a[i][n - j - 2];
        a[i][n - j - 2] --;
    }

    vector<P> q;
    
    auto check = [&](int i) {
        if (a[i].size() == 0) return;
        int j = a[i].back();
        if (a[j].back() == i) {
            if (i > j) swap(i,j);
            q.push_back(P(i,j));
        }
    };

    rep(i,n) check(i);

    int day = 0;
    while (q.size()) {
        day ++;
        sort(q.begin(),q.end());
        q.erase(unique(q.begin(),q.end()),q.end());
        vector<P> prevQ;
        swap(prevQ,q);
        for (P p: prevQ) {
            int i = p.first, j = p.second;
            a[i].pop_back();
            a[j].pop_back();
        }
        for (P p: prevQ) {
            int i = p.first,j = p.second;
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
}