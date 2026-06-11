#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    vector<set<int>> c(26);
    rep(i, n){
        c[s[i]-'a'].insert(i);
    }

    ll ans = 0;
    int l = 0;
    rep(i, t.size()){
        auto lb = c[t[i]-'a'].lower_bound(l);
        if(lb != c[t[i]-'a'].end()){
            ans += *lb - l + 1;
            l = *lb + 1;
        }else{
            ans += n - l + 1;
            l = 0;
            lb = c[t[i]-'a'].lower_bound(l);
            if(lb == c[t[i]-'a'].end()){
                cout << -1 << endl;
                return 0;
            }
            ans += *lb - l;
            l = *lb + 1;
        }
    }
    cout << ans << endl;
}