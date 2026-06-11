#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
int main() {
    string s;
    cin >> s;
    vector<int>v(s.size(), 0);
    s = s+"R";
    int r, l;
    r = l = 0;
    int pr, pl;
    rep(i, s.size() - 1) {
        if (s[i] == 'R'){
            r++;
            if (s[i+1] == 'L') {
                pr = i;
                pl = i+1;
            }
        }else if (s[i] == 'L'){
            l++;
            if (s[i + 1] == 'R') {
                v[pl] = r/2 + l - l/2;
                v[pr] = l/2 + r - r/2;
                r = l = 0;
            }
        }
        
    }
    rep(i, s.size() - 2) cout << v[i] << ' ';
    cout << v[s.size() - 2] << endl;
    return 0;
}
