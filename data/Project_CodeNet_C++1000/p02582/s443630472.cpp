#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int count;
    count = 0;
    for (int i = 0; i < 3; i++)
    {
        if (s[i] == 'R')
        {
            count++;
        }
    }
    if (s[1] == 'S' && count == 2)
    {
        count = 1;
    }
    cout << count << endl;
    return (0);
}
