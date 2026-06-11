#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    s.push_back('#');
    int ans = 0;
    for(int i = 0; i + 1 < s.size(); i++) {
        if(s[i] != s[i+1]) ans++;
    }
    cout << ans << endl;    
}