#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    char s[51]; cin >> s;

    int ans = 0;
    for (int i = 0; i <= n - 3; ++i) {
        ans += s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C';
    }

    cout << ans << endl;
}

