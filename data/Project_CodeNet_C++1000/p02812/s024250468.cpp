#include <iostream>
#include <string>
#include <vector>

#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)

using lint = long int;
using llint = long long int;
using namespace std;

int main() {
    fastIO;
    int n;
    string s;
    cin >> n >> s;

    int cnt = 0;
    for (size_t i = 0; i < s.size() - 2; i++) {
        if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
            cnt++;
        }
    }
    cout << cnt << endl;
}

