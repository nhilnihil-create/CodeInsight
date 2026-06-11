#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    int n;
    string s, s1, s2;
    cin >> n >> s;
    s1 = s.substr(0, n / 2);
    s2 = s.substr(n / 2);
    if (s1.compare(s2) == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}