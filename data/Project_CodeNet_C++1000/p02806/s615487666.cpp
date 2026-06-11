#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    string s[N];
    int t[N];
    for (int i=0; i<N; i++) cin >> s[i] >> t[i];
    string X; cin >> X;
    int ans = 0;
    bool flag = false;
    
    for (int i=0; i<N; i++) {
        if (flag) ans += t[i];
        if (s[i]==X) flag = true;
    }
    
    cout << ans << endl;
}