#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define Rep(i, s, n) for (int i = (int)s; i < (int)n; i++)
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    string res;
    if (s == "Sunny") res = "Cloudy";
    else if (s == "Cloudy") res = "Rainy";
    else res = "Sunny";
    cout << res << endl;
}