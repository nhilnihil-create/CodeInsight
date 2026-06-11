#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b;
    string sa , sb;
    cin >> a >> b;

    for(int i = 0; i < a; ++i)
    {
        sa += (char (b + 48));
    }

    for(int i = 0; i < b; ++i)
    {
        sb += (char (a + 48));
    }

    cout << (sa < sb ? sa : sb) << "\n";
    return 0;
}