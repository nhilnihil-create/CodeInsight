#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    char last = s[s.size() - 1];

    string ans;
    if (last == 's')
        ans = s + "es";
    else
        ans = s + "s";

    cout << ans << endl;
}