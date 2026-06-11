#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int ans = 0;
    string s;
    cin >> s;

    for (int i = 0, j = s.length() - 1; i != j && i < j ; i++, j--)
    {
        if (s[i] != s[j]) ans++;
    }

    cout << ans << endl;
}