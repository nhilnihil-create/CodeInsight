#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    bool ans = true;

    for(int i = 0; i < s.size(); i++) {
        if(i % 2 == 0 || i == 0) {
            if( s[i] == 'R' || s[i] == 'U' || s[i] == 'D') continue;
            else ans = false;
        }
        else if(i % 2 == 1) {
            if( s[i] == 'L' || s[i] == 'U' || s[i] == 'D') continue;
            else ans = false;
        }
    }

    if(ans) puts("Yes");
    else puts("No");
}