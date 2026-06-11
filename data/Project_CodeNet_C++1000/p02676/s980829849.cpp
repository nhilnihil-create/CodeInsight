#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string str;
    cin >> str;

    if (str.length() > n)
    {
        string rep = "...";
        str.replace(n, str.length(), rep);
        cout << str << endl;
    }
    else
    {
        cout << str << endl;
    }
}
