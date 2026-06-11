#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.length();
    if (n <= k)
    {
        cout << s;
    }
    else
    {
        s = s.substr(0, k) + "...";
        cout << s;
    }
}