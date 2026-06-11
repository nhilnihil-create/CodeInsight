#include <bits/stdc++.h>
#define ll long long
#define p pair<int, int>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s[n];
    vector<int> t(n);
    for (int i = 0; i < n; i++) cin >> s[i] >> t[i];
    string x;
    cin >> x;
    bool f = false;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (f) sum += t[i];
        if (s[i] == x) f = true;
    }
    cout << sum << endl;
    return 0;
}