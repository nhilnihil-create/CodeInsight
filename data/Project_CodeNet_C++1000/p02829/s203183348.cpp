#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    if(a == 1)
        cout << (b == 2 ? 3 : 2) << "\n";
    else if(b == 1)
        cout << (a == 2 ? 3 : 2) << "\n";
    else cout << 1 << "\n";
    return 0; 
}
