#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
using llint = long long int;
using namespace std;

int main() {
    fastIO;
    string s;
    cin >> s;
    string left = s.substr(0, s.size() / 2);
    string right = s.substr(s.size() / 2);
    reverse(right.begin(), right.end());

    int hug = 0;
    for (size_t i = 0; i < s.size() / 2; i++) {
        if (left.at(i) != right.at(i))
            hug++;
    }
    cout << hug << endl;
}
