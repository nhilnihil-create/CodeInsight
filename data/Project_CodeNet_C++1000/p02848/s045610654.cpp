#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (char t : s)
    {
        int shift = t - 'A' + n;
        shift %= 26;
        t = 'A' + shift;
        cout << t;
    }
    cout << endl;
}