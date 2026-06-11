#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    string s;
    cin >> s;
    if ((s[2] == s[3]) && s[4] == s[5]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}