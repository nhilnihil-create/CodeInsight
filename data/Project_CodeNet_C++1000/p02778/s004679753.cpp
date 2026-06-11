#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s, x;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        x += 'x';
    }

    cout << x << endl;
}