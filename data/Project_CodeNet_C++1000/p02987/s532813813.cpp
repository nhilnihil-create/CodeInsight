#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    char s1, s2, s3, s4;
    s1 = s[0];
    s2 = s[1];
    s3 = s[2];
    s4 = s[3];

    if (s1 == s2)
    {
        if ((s3 == s4) & (s2 != s3))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else if (s1 == s3)
    {
        if ((s2 == s4) & (s2 != s3))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else if (s1 == s4)
    {
        if ((s2 == s3) & (s1 != s3))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else
        cout << "No" << endl;
}