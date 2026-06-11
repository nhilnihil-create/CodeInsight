#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    string s;
    cin >> s;
    bool ans = true;
    while (true)
    {
        if (s.size() < 2)
        {
            ans = false;
            break;
        }
        if (s.substr(0, 2) != "hi")
        {
            ans = false;
            break;
        }
        s.erase(0, 2);
        if (s.size() == 0)
        {
            break;
        }
    }
    if (ans)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}