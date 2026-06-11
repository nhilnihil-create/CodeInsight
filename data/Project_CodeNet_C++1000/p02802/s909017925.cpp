#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<bool> ac(N, false), acc(N, false);
    vector<pair<int, string>> v;
    int pn = 0, cor = 0;
    rep(i, M) {
        int a;
        cin >> a;
        string s;
        cin >> s;
        v.push_back({a, s});
        if (s == "AC")
            ac[a] = true;
    }

    rep(i, M) {
        int a = v[i].first;
        string s = v[i].second;
        if (!ac[a])
            continue;
        if (!acc[a] && s == "WA")
            pn++;
        else if (!acc[a] && s == "AC")
            acc[a] = true, cor++;
    }

    cout << cor << " " << pn << endl;
}