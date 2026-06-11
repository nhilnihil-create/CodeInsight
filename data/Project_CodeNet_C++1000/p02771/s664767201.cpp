#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int n, cnt = 0, ans = 0;
    int a, b, c;
    cin >> a >> b >> c;
    set<int> s;

    s.insert(a);
    s.insert(b);
    s.insert(c);

    if (s.size() == 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}