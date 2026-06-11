#include <bits/stdc++.h>

using namespace std;

int main() {
    string n;
    cin >> n;
    int tot = 0;
    for (char c : n) tot += (c - '0');
    if (tot % 9 == 0) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}