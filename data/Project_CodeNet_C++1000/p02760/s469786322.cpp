#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    vector<vector<int>> a(3, vector<int>(3));
    vector<vector<bool>> check(3, vector<bool>(3, false));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }

    int n;
    cin >> n;
    int b;
    for (int i = 0; i < n; ++i) {
        cin >> b;
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (a[j][k] == b) check[j][k] = true;
            }
        }
    }

    bool flag = false;
    for (int i = 0; i < 3; ++i) {
        if (check[i][0] && check[i][1] && check[i][2]) flag = true;
    }
    for (int i = 0; i < 3; ++i) {
        if (check[0][i] && check[1][i] && check[2][i]) flag = true;
    }
    if (check[0][0] && check[1][1] && check[2][2]) flag = true;
    if (check[2][0] && check[1][1] && check[0][2]) flag = true;

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}