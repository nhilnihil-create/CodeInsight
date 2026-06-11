#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;
const ll MINF = LLONG_MIN;
const int INT_INF = INT_MAX;

int main()
{
    string s;
    cin >> s;
    bool res = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (i % 2 == 0)
        {
            if (!(s[i] == 'R' || s[i] == 'U' || s[i] == 'D'))
                res = false;
        }
        else
        {
            if (!(s[i] == 'L' || s[i] == 'U' || s[i] == 'D'))
                res = false;
        }
    }
    cout << (res ? "Yes" : "No") << endl;
}