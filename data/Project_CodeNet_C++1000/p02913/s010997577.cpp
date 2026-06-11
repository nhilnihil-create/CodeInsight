#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string x;
    cin >> n >> x;
    int mx = 0;
    for (int i = 0; i < n-  1; i++) {
        vector<int> pi = prefix_function(x.substr(i));
        for (int j = 0; j < pi.size(); j++) mx = max(mx, min(pi[j], (j + 1) / 2));
    }
    cout << mx;
    return 0;
}