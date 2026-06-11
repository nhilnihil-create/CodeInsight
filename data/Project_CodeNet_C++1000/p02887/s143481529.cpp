#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
        {
            ans++;
        }
    }
    cout << ans << "\n";
}