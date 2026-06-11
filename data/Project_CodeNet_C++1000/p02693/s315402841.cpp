#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, K;
    cin >> K >> A >> B;

    int i = 0;
    bool flag = false;

    while (K * i <= B)
    {
        if (K * i >= A)
        {
            flag = true;
        }
        i++;
    }

    if (flag)
        cout << "OK" << endl;
    else
        cout << "NG" << endl;
}
