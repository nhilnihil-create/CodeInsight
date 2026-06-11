#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, s;
    cin >> n >> k >> s;
    for(int i = 0; i < n; ++i) {
        if(i < k) cout << s << " ";
        else {
            if(s == 1e9) cout << s - 1 << " ";
            else cout << s + 1 << " ";
        }
    }
    cout << '\n';
    return 0;
}
