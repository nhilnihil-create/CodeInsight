#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string s; cin >> s;
    string t; cin >> t;
    bool flag = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != t[i]) flag = false;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}