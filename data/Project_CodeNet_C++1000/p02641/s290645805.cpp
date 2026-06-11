#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> Pil;

int X, N;
int p[110];

int main() {
    cin >> X >> N;
    for (int i = 0; i < N; i++) cin >> p[i];
    
    bool is_exist[101];
    memset(is_exist, false, sizeof(is_exist));

    for (int i = 0; i < N; i++) {
        is_exist[p[i]] = true;
    }

    int ans, diff;
    if (X > 50) {
        ans = 101; 
        diff = abs(101 - X);
    }
    else {
        ans = 0; 
        diff = abs(X);
    }

    for (int i = 100; i >= 0; i--) {
        if (!is_exist[i]) {
            if (diff >= abs(i - X)) {
                ans = i;
                diff = abs(i - X);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
