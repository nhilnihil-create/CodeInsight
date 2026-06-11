#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    if (s.substr(0, (n - 1) / 2) == s.substr((n + 3) / 2 - 1))
        cout
            << "Yes" << endl;
    else
        cout << "No" << endl;
}