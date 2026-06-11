#include <bits/stdc++.h>

using namespace std;

void fast();

/*
*
* Watch out! Another Buggy Code From Muhammad_Mamdouh, Happy Coding;
*
*/

int main()
{
    fast();
    string s, x; cin >> s >> x;

    int cnt = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] != x[i])
            ++cnt;
    }

    cout << cnt;

    return 0;
}

void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}