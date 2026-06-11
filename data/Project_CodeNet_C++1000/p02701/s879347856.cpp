#include <bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n;

    string s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];

    sort(s, s + n);

    int ans = 1; string prev = s[0]; 
    for (int i = 1; i < n; i++)
        if (prev != s[i]) {
            ans++;
            prev = s[i];
        }

    cout << ans;
}