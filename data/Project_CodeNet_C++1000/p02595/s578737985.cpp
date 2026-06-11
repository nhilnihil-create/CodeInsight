//  ©   ___MRX___

#include <bits/stdc++.h>
    using namespace std;

#define ll long long int

int main()
{
    int n;
    double d, x, y, flag = 0;

    cin >> n >> d;
    while(n--) {
        cin >> x >> y;
        x = abs(x);
        y = abs(y);
        if(sqrt(x * x + y * y) <= d)
            flag++;
    }

    cout << flag << '\n';

    return 0;
}
