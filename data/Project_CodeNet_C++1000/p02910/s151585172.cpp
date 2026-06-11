#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if ((!(i & 1) && (s[i] == 'L')) || ((i & 1) && (s[i] == 'R')))
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}