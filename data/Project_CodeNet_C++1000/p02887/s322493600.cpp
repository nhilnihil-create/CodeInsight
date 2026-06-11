#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
string s;
int32_t main() {
    int ans = 0;
    cin >> n >> s;
    for(int i = 0; i < s.length()-1; ++i) {
        if (s[i] != s[i+1]) ++ans;
    }
    cout << ans+1;
}