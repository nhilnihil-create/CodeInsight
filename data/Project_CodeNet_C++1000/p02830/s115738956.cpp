#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    int cnt = 0;
    while (cnt < n)
    {
        cout << s[cnt];
        cout << t[cnt++];
    }
    cout << endl;
    return 0;
}