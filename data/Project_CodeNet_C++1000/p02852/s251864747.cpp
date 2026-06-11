#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> dp(n+1, 0);
    int idx = n;
    while(idx > 0){
        bool find = false;
        for(int t = max(0, idx-m); t < idx; t++){
            if(s[t] == '0'){
                dp[t] = idx - t;
                idx = t;
                find = true;
                break;
            }
        }
        if(!find){
            cout << -1 << endl;
            return 0;
        }
    }
    idx = 0;
    while(idx < n){
        cout << dp[idx] << ' ';
        idx += dp[idx];
    }
    cout << endl;
}