#include<bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int n;
    n = t.size();
    if (t.erase(n - 1, 1) == s) cout << "Yes" << endl;
    else cout << "No" << endl;
}