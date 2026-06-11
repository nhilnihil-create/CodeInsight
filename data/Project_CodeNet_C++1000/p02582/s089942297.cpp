#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin >> s;
    int n = s.length();
    int rc = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i){
        if(s[i] == 'R'){
            ++rc;
            ans = max(ans, rc);
        }
        else {rc = 0;}
    }
    
    cout << ans << endl;
}