#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;
    if (n < str.size()) {
        for (int i = 0; i < n; i++) {
            cout << str[i];
        }
        cout << "..." << endl;
    } else {
        cout << str << endl;
    }
    return 0;
}