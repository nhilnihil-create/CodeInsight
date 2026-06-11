#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int i, sum;
    i = 0;
    sum = 0;
    cin >> s;
    while (s[i] != '\0')
    {
        sum += s[i] - '0';
        i++;
    }
    if (sum % 9 == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return (0);
}
