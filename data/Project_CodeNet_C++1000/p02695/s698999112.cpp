#include <bits/stdc++.h>


using namespace std;


int N, M, Q;
int ans;
vector<int> A;
vector<tuple<int, int, int, int>> conditions;


int calc(void) {
    int ret = 0;
    for (auto t : conditions) {
        int a, b, c, d;
        a = get<0>(t);
        b = get<1>(t);
        c = get<2>(t);
        d = get<3>(t);

        if (A[b] - A[a] == c) {
            ret += d;
        }
    }
    return ret;
}


void solve_sub(int depth) {
    if (depth == N) {
        ans = max(ans, calc());
        return;
    }

    int a_now = *A.rbegin();
    for (int a_next = a_now; a_next <= M; a_next++) {
        A.push_back(a_next);
        solve_sub(depth + 1);
        A.pop_back();
    }
}


void solve(void) {
    for (int i = 1; i <= M; i++) {
        A.push_back(i);
        solve_sub(0);
        A.pop_back();
    }
}


int main(void) {
    cin >> N >> M >> Q;
    for (int i = 0; i < Q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        conditions.push_back(make_tuple(a, b, c, d));
    }

    solve();

    cout << ans << endl;
}
