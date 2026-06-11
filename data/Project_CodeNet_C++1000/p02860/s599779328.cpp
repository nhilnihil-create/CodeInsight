#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    string s;
    cin >> n >> s;
    if (n % 2 == 1)
    {
        cout << "No" << endl;
        return 0;
    }
    bool flag = true;
    for (long long i = 0; i < n / 2; i++)
    {
        if (s[i] != s[i + n / 2])
            flag = false;
    }
    if (flag)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}