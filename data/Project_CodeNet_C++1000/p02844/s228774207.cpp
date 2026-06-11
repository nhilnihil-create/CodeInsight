#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    string s;
    cin >> n >> s;
    vector<string> v;
    for(char i = '0'; i <= '9'; i++) {
        for(char j = '0'; j <= '9'; j++) {
            for(char k = '0'; k <= '9'; k++) {
                string tmp(3, 0);
                tmp[0] = i; tmp[1] = j; tmp[2] = k;
                v.push_back(tmp);
            }
        }
    }
    ll ans = 0;
    for(auto e : v) {
        ll itr = 0;
        bool f = false;
        rep(i, 0, n) {
            if(s[i] == e[itr]) itr++;
            if(itr == 3) {
                f = true;
                break;
            }
        }
        if(f) ans++;
    }
    cout << ans << endl;
    return 0;
}