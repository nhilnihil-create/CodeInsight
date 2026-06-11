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

    for (auto ch : s) {
        if ((int)ch + n > 90) {
            cout << (char)(ch + n - 26);
        } else {
            cout << (char)(ch + n);
        }
    }
    cout << endl;
}

