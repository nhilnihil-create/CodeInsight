#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<long long> a(n+1, 0);
    for(int i = 0; i < n; i++) {
        if(s[i] == '<') {
            a[i+1] = max(a[i]+1, a[i+1]);
        }
    }
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == '>') {
            a[i] = max(a[i], a[i+1]+1);
        }
    }
    long long ans = 0;
    for(auto au : a) {
        ans += au;
    }
    cout << ans << "\n";
    return 0;
}