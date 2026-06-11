#include <bits/stdc++.h>
using namespace std;

bool is_square(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string s;
    cin >> s;
    int ans = 0;
    string a = "";
    string b = "";
    for (size_t i = 0; i < s.length(); i++)
    {
        b += s.substr(i, 1);
        if (a != b)
        {
            ans++;
            a = b;
            b = "";
        }
        else
        {
        }
        /* code */
    }
    cout << ans << endl;

    return 0;
}