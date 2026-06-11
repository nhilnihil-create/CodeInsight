#include <bits/stdc++.h>
using namespace std;

int main()
{

    int A, B;
    cin >> A >> B;
    bool can = false;

    for (int j = 0; j <= 10000; j++)
    {
        if (int(j * 0.08) == A && int(j * 0.1) == B)
        {
            cout << j << endl;
            can = true;
            break;
        }
        }
    if(can==false)
    {
        cout << -1 << endl;
    }
}
