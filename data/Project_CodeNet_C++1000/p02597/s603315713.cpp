#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    map<int, int> mk;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'R') {
            mk[i] = 1;
            cnt++;
        }
    }
    int ans = 0;
    for(int i = 0; i < cnt; i++) {
        if(!mk[i]) ans++;
    }
    cout << ans << "\n";


    return 0;
}
