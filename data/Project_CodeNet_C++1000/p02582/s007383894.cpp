#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> Pil;

string S;

int main() {
    cin >> S;

    int ans = 0;
    int now = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'R') {
            now++;
        }
        else {
            ans = max(ans, now);
            now = 0;
        }
    }

    ans = max(ans, now);
    now = 0;

    cout << ans << endl;
    
    return 0;
}
