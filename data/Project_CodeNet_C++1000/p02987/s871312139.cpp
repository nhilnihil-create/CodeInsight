#include<bits/stdc++.h>
using namespace std;
int main() {
    set<char> letters;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        letters.insert(s[i]);
    }
    if (letters.size() == 2) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    return 0;
}