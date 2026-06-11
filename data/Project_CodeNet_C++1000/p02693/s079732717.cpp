#include <bits/stdc++.h>
using namespace std;

int main()
{
    int K, A, B;
    cin >> K;
    cin >> A >> B;
    for (int i = 0; i <= (B - A); i++)
    {
        if ((A + i) % K == 0)
        {
            cout << "OK" << endl;
            break;
        }
        else if ((A + i) % K != 0)
        {
            if (i < (B - A))
            {
                continue;
            }
            if(i == (B - A))
            {
                cout << "NG" << endl;
            }
        }
    }
}