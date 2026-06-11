#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;
    vector<int> v(26);
    for(int i = 0; i < 4; i++) {
        v[s[i]-'A']++;
    }
    for(int i = 0; i < 26; i++) {
        if(v[i] == 1 || v[i] == 3 || v[i] == 4) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}