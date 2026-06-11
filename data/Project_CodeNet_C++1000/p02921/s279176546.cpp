#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string s, t;
    cin >> s >> t;
    int cnt = 0;
    if (s[0] == t[0])
        cnt++;
    if (s[1] == t[1])
        cnt++;
    if (s[2] == t[2])
        cnt++;
    cout << cnt << endl;
    return 0;
}
