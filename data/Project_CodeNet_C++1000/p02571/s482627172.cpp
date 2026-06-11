#include <bits/stdc++.h>

using namespace std;

int main() {
    string s,t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int ans = n;
    for(int i = 0; i + m - 1< n; ++i){
        int count = 0;
        for(int j = 0; j < m; ++j){
            if(s[j+i] != t[j])count ++;
        }
        ans = min(ans,count);
    }
    cout << ans <<"\n";
}