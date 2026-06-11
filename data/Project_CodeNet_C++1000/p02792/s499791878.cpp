#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int INF = 1001001001;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(10, vector<int>(10));
    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        int begin = s[0] - '0';
        int end = s[s.size()-1] - '0';
        a[begin][end]++;
    } 
    int ans = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            ans += a[i][j] * a[j][i];
        }
    }
    cout << ans << endl;
    return 0;
}