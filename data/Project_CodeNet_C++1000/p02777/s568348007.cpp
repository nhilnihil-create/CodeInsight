#include <cmath>
#include <iostream>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    string s, t, u;
    int a, b;

    cin >> s >> t;
    cin >> a >> b;
    cin >> u;

    a -= (s == u);
    b -= (t == u);

    cout << a << " " << b << endl;

    return 0;
}
