#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    long long ans = 0;
    long long run = 0;
    long long prev_climax = 0;
    for (int i=0; i<=s.length(); i++) {
        if (i == s.length() || (i > 0 && s[i] != s[i - 1])) {
            if (s[i - 1] == '<') {
                ans += (run + 1) * run / 2;
                prev_climax = run;
            } else {
                ans += (run + 1) * run / 2;
                ans -= min(prev_climax, run);
            }
            run = 1;
        } else {
            run++;
        }
    }
    cout << ans << "\n";
}