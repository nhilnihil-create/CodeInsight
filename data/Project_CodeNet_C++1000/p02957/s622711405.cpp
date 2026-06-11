//  ©   ___MRX___

#include <bits/stdc++.h>
    using namespace std;

#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, x;
    cin >> a >> b;
    x = a + b;

    if(x % 2) {
        cout << "IMPOSSIBLE" << '\n';
    }
    else {
        cout << x / 2 << '\n';
    }

    return 0;
}
