#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, ans = "No";
    cin >> s;
    
    set<int> buf;
    for (int i = 0; i < 4; i++) {
        buf.insert(s[i]);
    }
    
    if (buf.size() == 2) {
        ans = "Yes";
    }
    
    cout << ans << endl;
    return 0;
}
