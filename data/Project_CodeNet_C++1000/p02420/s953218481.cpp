#include <iostream>
using namespace std;

int main()
{
    string str, str_tail, str_top;
    int h, m;
    while (cin >> str)
    {
        // cout << "str = " << str << endl;
        if (str == "-")
        {
            break;
        }

        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            cin >> h;
            string s1;
            str_top = str.substr(0, h);
            str_tail = str.substr(h, str.length() - h);
            str = str_tail + str_top;
        }
        cout << str << endl;
    }
    return 0;
}
