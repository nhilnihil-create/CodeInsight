#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
using vi = vector<int>;
template <class T>
using Grid = vector<vector<T>>;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    rep(i, N) cin >> v[i];
    int ans = 0, cnt = 0;
    rep(i, N - 1) {
        if (v[i] >= v[i + 1])
            cnt++;
        else {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    ans = max(ans, cnt);
    cout << ans << endl;
}