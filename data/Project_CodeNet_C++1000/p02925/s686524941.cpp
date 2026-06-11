//
// Created by Hideaki Imamura on 2020-03-25.
//
# include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <ll, ll> l_l;
typedef pair<int, int> i_i;

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

# define EPS (1e-7)
# define INF (1e9)
# define PI (acos(-1))
//const ll mod = 1000000007;

int N;
vector<queue<int>> a;

int main() {
    cin >> N;
    a.assign(N, queue<int>());
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            int tmp;
            cin >> tmp;
            a[i].push(tmp - 1);
        }
    }

    set<i_i> q;
    auto check = [&](int i) {
        if (a[i].size() == 0) return;
        int j = a[i].front();
        if (a[j].size() == 0) return;
        if (a[j].front() == i) {
            i_i p(i, j);
            if (p.second < p.first) swap(p.first, p.second);
            q.insert(p);
        }
    };

    for (int i = 0; i < N; ++i) check(i);

    int ans = 0;
    while (!q.empty()) {
        ans++;
        set<i_i> prev_q;
        swap(prev_q, q);
        for (i_i p : prev_q) {
            int i = p.first, j = p.second;
            a[i].pop();
            a[j].pop();
        }
        for (i_i p : prev_q) {
            int i = p.first, j = p.second;
            check(i);
            check(j);
        }
    }
    for (int i = 0; i < N; ++i) {
        if (a[i].size() != 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}