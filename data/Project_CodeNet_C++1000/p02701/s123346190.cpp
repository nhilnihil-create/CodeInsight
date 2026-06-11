#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    sort(s.begin(), s.end());
    int d = 0;
    for (int i = 0; i < n-1; i++) {
        if (s[i] == s[i+1]) d++;
    }

    cout << n-d << endl;
}