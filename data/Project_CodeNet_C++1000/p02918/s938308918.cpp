#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = 0;
    char c = 'E';
    rep(i, s.size()){
        if(c == s[i])cnt++;
        c = s[i];
    }
    int ans = min(cnt + k * 2, n - 1);
    cout << ans << endl;
}