#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s.length() % 2 != 0)
    {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s.substr(2 * i, 2) != "hi")
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}