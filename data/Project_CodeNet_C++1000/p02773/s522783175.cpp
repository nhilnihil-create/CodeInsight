#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    int n;
    cin >> n;
    
    map<string,int> m;
    vector<string> s(n);
    rep(i,n) {
        cin >> s[i];
        m[s[i]]++;
    }
    
    sort(s.begin(), s.end());
    
    int ma = 0;
    rep(i,n) {
        //cout << s[i] << endl;
        if(ma < m[s[i]])
            ma = m[s[i]];
    }
    
    string ans = "";
    rep(i,n) {
        if(ma == m[s[i]] && ans != s[i]) {
            ans = s[i];
            cout << ans << endl;
        }
    }
    
    
    
    return 0;
}


