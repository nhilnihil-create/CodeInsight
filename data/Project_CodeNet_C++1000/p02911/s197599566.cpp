#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K, Q;
    cin >> N >> K >> Q;
    map<int, int> ma;
    vector<int> p(N, K);
    rep(i, Q) {
        int a;
        cin >> a;
        a--;
        p[a]++;
    }

    rep(i, N) { p[i] -= Q; }

    rep(i, N) {
        if (p[i] <= 0)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}