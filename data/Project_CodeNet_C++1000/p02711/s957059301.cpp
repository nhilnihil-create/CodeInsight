#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    rep(i, 3) {
        if (n % 10 == 7) {
            cout << "Yes" << endl;
            return 0;
        }
        n /= 10;
    }
    cout << "No" << endl;
    return 0;
}
