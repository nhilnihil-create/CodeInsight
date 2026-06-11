#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
string s, t;

int main()
{
    cin >> s >> t;
    string sub = t.substr(0, t.length() - 1);
    // cout << sub << endl;
    if (s == sub)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
