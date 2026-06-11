#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, ans = 0; string s; cin >> n >> s;

    for(int i = 1; i < n; i++) {
        int d = 1;
        for(int j = 0; i + j < n; j++) {
            if(s[j] == s[i+j]) ans = max(ans, min(i, d++));
            else d = 1;
        }
    }
    cout << ans;
}