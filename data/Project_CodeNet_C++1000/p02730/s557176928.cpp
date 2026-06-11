#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string s) {
    bool res = true;
    for (int i = 0; i < (s.size()/2); i++) {
        if (s.at(i) != s.at(s.size()-1-i)) res = false;
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    
    if (is_palindrome(s)
            && is_palindrome(s.substr(0, ((s.size()-1)/2)))
            && is_palindrome(s.substr(((s.size()+1)/2), ((s.size()-1)/2)))) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
