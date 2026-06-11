#include <bits/stdc++.h>
using namespace std;

int ctoi(char);

int main()
{
    string s;
    // char strs;    

    while (1)
    {
        cin >> s;
        if (s == "0") break;
        int digs = 0;
        for (long unsigned int i = 0; i < s.length(); i++) {
            // char strs = s[i];
            digs += ctoi(s[i]);
        }
        cout << digs << endl;
    }
    return 0;
}

int ctoi(char c)
{
    switch (c)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    default:
        return 0;
    }
}
