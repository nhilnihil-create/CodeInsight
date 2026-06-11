#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, a, b;
    cin >> k >> a >> b;
    if (b / k > (a-1) / k)
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "NG" << endl;
    }
    return 0;
}