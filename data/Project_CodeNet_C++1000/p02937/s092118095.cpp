#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    
    int n = s.size(), m = t.size();
    
    vector<vector<int>> is(26);
    
    for (int i = 0; i < n; i++) is[s[i]-'a'].push_back(i);
    for (int i = 0; i < n; i++) is[s[i]-'a'].push_back(i+n);
    
    long long ans = 0;
    
    int p = 0;
    
    for (int i = 0; i < m; i++){
        int c = t[i] - 'a';
        if (is[c].size() == 0){
            cout << -1 << endl;
            return 0;
        }
        
        p = *lower_bound(is[c].begin(),is[c].end(),p) + 1;
        if (p >= n) p -= n, ans += n;
    }
    
    ans += p;
    cout << ans << endl;
    return 0;
}