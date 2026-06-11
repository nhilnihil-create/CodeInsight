#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string s; cin >> s;
    bool flag = true;
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            cout << "No" << endl;
            return 0;
        }
        if (s[i] != s[n / 2 - i - 1])
        {
            cout << "No" << endl;
            return 0;
        }
        if (s[i + n / 2 + 1] != s[n - i - 1])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}