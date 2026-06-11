#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    int l = s.size() - 1;
    if(s[l] == 's') {
        s += "es";
    }
    else {
        s += "s";
    }
    cout << s;
    return 0;
}