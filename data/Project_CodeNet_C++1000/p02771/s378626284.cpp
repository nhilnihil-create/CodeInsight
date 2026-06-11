#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int a, b, c; cin >> a >> b >> c;
    if (a == b && b == c && c == a)
        cout << "No" << endl;
    else
    {
        if (a == b || b == c || c == a)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}