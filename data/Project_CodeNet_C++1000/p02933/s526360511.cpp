#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int a;
    string s;
    cin >> a >> s;

    if (a >= 3200) {
        cout << s << endl;
    } else {
        cout << "red" << endl;
    }
    return 0;
}