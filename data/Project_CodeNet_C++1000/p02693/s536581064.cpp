#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, a, b;
    cin >> k >> a >> b;

    bool ng = true;
    for(int i = a; i <= b; ++i)
    {
        if(i % k == 0) ng = false;
    }

    cout << (ng ? "NG" : "OK") << "\n";
    return 0;
}