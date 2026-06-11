#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
    string s, t;
    cin >> s >> t;
    int ans = 1;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != t[i])
        {
            ans = 0;
            break;
        }
    }
    cout << ((ans == 1) ? "Yes" : "No") << endl;
    return 0;
}
