#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n;
    cin >> n;

    int prev = 2e9 , len = 0 , ans = 0;
    for (int i = 0 ;i < n ;i++) {
        int x;
        cin >> x;
        if (x <= prev)
            len++;
        else
            len = 1;
        prev = x;
        ans = max(ans , len - 1);
    }

    cout << ans;
}
