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
    cin >> n;

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (1 <= i && i <= 9)
            cnt++;
        else if (100 <= i && i <= 999)
            cnt++;
        else if (10000 <= i && i <= 99999)
            cnt++;
    }
    cout << cnt << endl;
}

