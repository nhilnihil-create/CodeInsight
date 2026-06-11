#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    rep(i, n){
        if(i == n - 1)ans++;
        else if(s[i] == s[i+1]){
            if(i == n - 2){
                ans++;
                break;
            }else{
                ans += 2;
                i += 2;
            }
        }else ans++;
    }
    cout << ans << endl;
}