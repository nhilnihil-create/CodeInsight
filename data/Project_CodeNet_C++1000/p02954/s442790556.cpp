#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    string s; cin >> s;
    int n = s.size();

    int l = 0;
    int to[n]; rep(i,n) to[i] = -1;
    for (int i = 1; i < n; i++) {
        if (s[i] != 'R') {
            for (int j = l; j < i; j++) {
                to[j] = i-1;
            }
            l = i+1;
        }
    }
    int r = n-1;
    for (int i = n-2; i >= 0; i--) {
        if (s[i] != 'L') {
            for (int j = r; j > i; j--) {
                to[j] = i+1;
            }
            r = i-1;
        }
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
