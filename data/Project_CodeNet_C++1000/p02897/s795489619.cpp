#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n == 1)
        cout << 1 << "\n";
    else 
        cout << double (n % 2 == 0 ? 0.5 : (double(n / 2 + 1) / n)) << "\n";
    return 0;
}
