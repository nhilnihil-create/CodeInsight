#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool jg = true;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int b = a % 2;
        int c = a % 3;
        int d = a % 5;
        if (b == 1)
            continue;
        else if (b == 0 && (c == 0 || d == 0))
            continue;
        else
        {
            jg = false;
            break;
        }
    }

    if (jg == true)
        cout << "APPROVED" << endl;
    else
        cout << "DENIED" << endl;
}