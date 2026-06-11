#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int ans = 0;
    int n = s.length();
    char t = '.';
    for(int i=0; i<n; i++){
        ans += 1;

        if(t == s[i]){ t = '.'; i += 1; if(i >= n) ans -= 1; }
        else t = s[i];
    }
    cout << ans << endl;
    return 0;
}