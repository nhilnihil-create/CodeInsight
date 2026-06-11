#include <bits/stdc++.h>
using namespace std;
int main() {
    string t;
    cin >> t;
    cout << regex_replace(t, regex("\\?"), "D");
    return 0;
}