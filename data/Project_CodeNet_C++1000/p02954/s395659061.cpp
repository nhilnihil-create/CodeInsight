#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    string s; cin >> s;
    int n = s.size();

    int l = 0;
    char c = 'R';
    int to[n]; rep(i,n) to[i] = -1;
    for (int i = 1; i < n; i++) {
        if (c != s[i]) {
            for (int j = l; j < i; j++) {
                if (c == 'R') to[j] = i-1;
                else to[j] = l;
            }
            l = i;
            c = s[i];
        }
    }
    for (int j = l; j < n; j++) {
        to[j] = l;
    }

    int ans[n]; rep(i,n) ans[i] = 0;
    rep(i,n) {
        if (abs(i-to[i])%2) {
            if (s[i] == 'R') ans[to[i]+1]++;
            else ans[to[i]-1]++;
        }
        else ans[to[i]]++;
    }
    rep(i,n-1) printf("%d ", ans[i]);
    printf("%d\n",ans[n-1]);

    return 0;
}
