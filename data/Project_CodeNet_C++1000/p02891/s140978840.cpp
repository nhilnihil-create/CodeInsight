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
    ll k;
    cin >> k;
    vector<int> cnt;
    char c = s[0];
    int m = 1;
    for(int i = 1; i < n; i++){
        if(s[i] != c){
            cnt.push_back(m);
            m = 1;
            c = s[i];
        }else{
            m++;
        }
    }
    cnt.push_back(m);
    m = cnt.size();
    if(m == 1){
        cout << k * cnt[0] / 2 << endl;
    }else{
        if(s[0] != s[n-1]){
            ll ans = 0;
            for(int l : cnt){
                ans += (l / 2) * k;
            }
            cout << ans << endl;
        }else{
            ll ans = 0;
            for(int i = 1; i < m-1; i++){
                ans += (cnt[i] / 2) * k;
            }
            ans += cnt[0] / 2 + cnt[m-1] / 2;
            ans += (cnt[0] + cnt[m-1]) / 2 * (k-1);
            cout << ans << endl;
        }
    }
}