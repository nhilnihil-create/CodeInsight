#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long int;

int main()
{
    string s, t; cin >> s >> t;
    vector<int> index[26]; // 0-indexed
    int n = s.size();
    rep(si, n){
        char c = s[si];
        int ci = c-'a';
        index[ci].push_back(si);
        index[ci].push_back(si+n);
    }

    bool exists[26];
    fill_n(exists, 26, false);
    rep(ti, t.size()){
        char c = t[ti];
        exists[(c-'a')] = true;
    }
    rep(c, 26){
        if(exists[c] && index[c].size() == 0){
            cout << -1 << endl;
            return 0;
        }
        sort(index[c].begin(), index[c].end());
    }

    ll ans; // 0-indexed but the real answer is 1-indexed
    rep(i, t.size()){
        char ti = t[i];
        int idx = ti - 'a';
        if(i == 0){
            ans = index[idx][0];
            continue;
        }

        ll state = (ans % n);
        ll next = *(upper_bound(index[idx].begin(), index[idx].end(), state));
        ans += (next - state);
    }

    cout << ans + 1 << endl;
    return 0;
}