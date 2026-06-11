#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int n;
    cin >> n;
    string g;
    set<string> s;
    rep(i, n) {
        cin >> g;
        s.insert(g);
    }
    cout << s.size() << endl;
    return 0;
}