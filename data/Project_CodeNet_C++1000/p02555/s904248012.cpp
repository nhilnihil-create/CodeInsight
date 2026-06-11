#include <iostream>

using namespace std;

typedef long long ll;

const ll mod = 1000000007;

ll ans[2001];

int main() {
    int s;
    cin >> s;
    for(int i = 3; i < 2001; ++i) {
        ans[i] = 1;
    }
    for(int i = 3; i <= s; ++i) {
        for(int j = 3; j <= i; ++j) {
            ans[i] = (ans[i] + ans[i-j]) % mod;
        }
    }
    cout << ans[s];
}