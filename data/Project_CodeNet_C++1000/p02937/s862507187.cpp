#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    string s, t; cin >> s >> t;
    LL n = s.length(), m = t.length(), cur = -1, rep = 0;
    vector<vector<LL>> v(26);

    for(int i = 0; i < n; i++) v[s[i]-'a'].push_back(i);

    for(char c : t) {
        if(v[c-'a'].empty()) return cout << -1, 0;

        auto it = upper_bound(v[c-'a'].begin(), v[c-'a'].end(), cur);

        if(it == v[c-'a'].end()) rep++, cur = *v[c-'a'].begin();
        else cur = *it;
    }  

    cout << rep * n + cur + 1;
}