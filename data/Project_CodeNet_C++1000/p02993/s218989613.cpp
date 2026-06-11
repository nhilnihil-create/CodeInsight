#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    bool a = true;
    for (int i = 0; i < s.size()-1; i++) {
        if (s[i] == s[i+1]) a = false;
    }
    if(a) cout << "Good" << endl;
    else cout << "Bad" << endl;
    
    return 0;
}