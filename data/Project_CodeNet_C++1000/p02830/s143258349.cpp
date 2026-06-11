#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    
    string s, t;
    cin >> s >> t;
    
    string ans = "";
    for (int i = 0; i < n; i++){
        ans += s[i];
        ans += t[i];
    }
    
    cout << ans << endl;
}
