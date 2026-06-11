#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

/*
How to use:
- input :   std::string
- output :  std::vector<std::pair<char, long long>>
    - first:    character
    - second:   count

Note that any element of input must not be -1.
*/
vector<pair<char,ll>> run_length_encoding(string s){
    vector<pair<char,ll>> res;
    ll n = s.size();
    char prev = -1;
    ll cur = 1;
    for(ll i = 0; i < n; i++) {
        if(prev == s[i]) cur++;
        else {
            if(prev != -1) res.push_back({prev, cur});
            prev = s[i];
            cur = 1;
        } 
    }
    res.push_back({prev, cur});
    return res;
}

int main(){
    string s;
    cin >> s;
    ll n = s.size();
    ll cnt = 0;
    char cur = 'R';
    s.push_back('R');
    vector<ll> ans(n+19, 0);
    rep(i, 0, n+1) {
        if(cur == s[i]) cnt++;
        else {
            if(cur == 'R') {
                ans[i] += cnt / 2;
                ans[i-1] += (cnt + 1) / 2;
                cur = 'L';
                cnt = 1;
            } else {
                ans[i-cnt] += (cnt + 1) / 2;
                ans[i-cnt-1] += cnt / 2;
                cur = 'R';
                cnt = 1;
            }
        }
    }
    rep(i, 0, n) cout << ans[i] << (i == n-1 ? "\n" : " ");
    return 0;
}