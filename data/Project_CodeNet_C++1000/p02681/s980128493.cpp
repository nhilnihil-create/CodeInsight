#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string s = "";
    string t = "";
    cin >> s;
    cin >> t;

    if (t.substr(0, s.length()).compare(s) == 0)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}