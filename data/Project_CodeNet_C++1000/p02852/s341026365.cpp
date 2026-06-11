#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    string S;
    cin >> N >> M >> S;

    vector<int> iszero;
    for (int i = 0; i <= N; ++i)
        if (S[i] == '0')
            iszero.push_back(i);

    bool isok = true;
    vector<int> ans;
    int idx = N;
    while (idx) {
        auto itr = lower_bound(iszero.begin(), iszero.end(), idx - M);
        if (*itr >= idx) {
            isok = false;
            break;
        }
        ans.push_back(idx - *itr);
        idx = *itr;
    }

    if (isok)
        for (auto itr = ans.rbegin(); itr != ans.rend(); ++itr)
            cout << *itr << " ";
    else
        cout << -1;
    cout << endl;
    return 0;
}
