#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int n;
struct abdata {
    long long a; long long b;
};

bool cmp(const abdata &aa, const abdata &bb) {
    return aa.a > bb.a;
}

vector< vector<long long> > dp(2020, vector<long long>(2020, 0));

int main() {
    cin >> n;
    vector<abdata> ain(n);
    for(int i = 0; i < n; ++i) {
        cin >> ain.at(i).a;
        ain.at(i).b = i;
    }
    sort(ain.begin(), ain.end(), cmp);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; i+j < n; ++j) {
            chmax(dp[i+1][j], dp[i][j] + ain.at(i+j).a * (ain.at(i+j).b - i));
            chmax(dp[i][j+1], dp[i][j] + ain.at(i+j).a * ((n-1-j) - ain.at(i+j).b));
        }
    }

    long long ans = 0;
    for(int i = 0; i <= n; ++i) {
        chmax(ans, dp[i][n-i]);
    }

    cout << ans << endl;
}