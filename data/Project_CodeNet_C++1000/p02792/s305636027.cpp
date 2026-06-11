#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<vector<ll>> A(10, vector<ll>(10));
    for (int i = 0; i <= N; i++) {
        string s = to_string(i);
        int top = s[0] - '0';
        int bottom = s[s.size() - 1] - '0';
        A[top][bottom]++;
    }

    ll ans = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            ans += A[i][j] * A[j][i];
        }
    }

    cout << ans - 1 << endl;
}