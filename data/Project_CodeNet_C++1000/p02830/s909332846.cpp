#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    for(int i = 0; i < n; ++i)
        cout << s[i] << t[i];

    cout << "\n";
    return 0;
}