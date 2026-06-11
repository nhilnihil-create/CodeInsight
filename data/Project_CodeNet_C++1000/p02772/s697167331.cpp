#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; cin >> n;
    int a;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a % 2 == 0)
        {
            if (a % 3 != 0 && a % 5 != 0)
                flag = false;
        }
    }
    if (flag)
        cout << "APPROVED" << endl;
    else
        cout << "DENIED" << endl;
}