#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main(int argc, char *argv[])
{
    int n, a, b;
    string str, command, buff;
    cin >> str >> n;
    while (n--)
    {
        cin >> command >> a >> b;
        if (command == "print")
        {
            cout << str.substr(a, b - a + 1) << endl;
        }
        else if (command == "reverse")
        {
            string sub = str.substr(a, b - a + 1);
            reverse(sub.begin(), sub.end());
            str = str.substr(0, a) + sub + str.substr(b + 1);
        }
        else if (command == "replace")
        {
            cin >> buff;
            str.replace(a, b - a + 1, buff);
        }
    }
    return 0;
}
