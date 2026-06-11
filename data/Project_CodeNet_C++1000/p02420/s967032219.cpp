#include <iostream>
#include <string>
using namespace std;
int main()
{
    int cnt, h;
    string s, ts;
    while (true)
    {
        cin >> s;
        if (s == "-")
            break;

        cin >> cnt;
        for (int i = 0; i < cnt; i++)
        {
            cin >> h;
            ts = s.substr(0, h);
            s = s.substr(h) + ts;
        }

        cout << s << endl;
    }
}
