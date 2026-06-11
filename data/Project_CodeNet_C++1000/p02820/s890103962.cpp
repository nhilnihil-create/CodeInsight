
#include <bits/stdc++.h>

using namespace std;

typedef long int lint;
typedef long long int llint;

#define INF 1073741824
#define LINF 4611686018000000000
#define MOD 1000000007

int win(char c) {
    if (c == 'r') return 2;
    if (c == 's') return 0;
    return 1;
}

int main() {
    int n, k;
    cin >> n >> k;
    int rsp[3];
    for (int i = 0; i < 3; i++) cin >> rsp[i];
    string t;
    cin >> t;
    int ans = 0;
    int prev;
    for (int i = 0; i < k; i++) {
        prev = -1;
        for (int j = i; j < n; j += k) {
            int tmp = win(t[j]);
            if (prev != tmp) {
                prev = tmp;
                ans += rsp[prev];
            } else {
                prev = -1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
