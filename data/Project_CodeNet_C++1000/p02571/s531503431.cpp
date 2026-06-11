#include<bits/stdc++.h>
using namespace std;
string s, t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    cin >> s >> t;
    int n = s.size(), m = t.size();

    int ans = INT_MAX;
    for (int i = 0; i <= n - m; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (s[i + j] != t[j]) cnt++;
        }
        ans = min(ans, cnt);
    }

    cout << ans << '\n';

    return 0;
}
