#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int n, ans1 = 0, ans2 = 0;
    cin >> n;
    rep(i, n) {
        int a;
        cin >> a;
        if (a % 2 == 0) {
            ans1++;
            if (a % 3 == 0 || a % 5 == 0)
                ans2++;
        }
    }
    if (ans1 == ans2)
        cout << "APPROVED" << endl;
    else
        cout << "DENIED" << endl;
    return 0;
}