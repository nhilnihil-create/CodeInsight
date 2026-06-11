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
    string s, t;

    cin >> n >> s >> t;

    rep(i, n) cout << s.at(i) << t.at(i);
    cout << endl;
}

