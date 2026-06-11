//  ©   ___MRX___

#include <bits/stdc++.h>
    using namespace std;

#define ll long long int

int main()
{
    int n, i;
    bool checker = false;

    cin >> n;

    for(i = 1; i < 10; i++) {
        if(n / i < 10 && n % i == 0) {
            checker = true;
            break;
        }
    }
    checker ? cout << "Yes" <<'\n' : cout << "No" << '\n';

    return 0;
}
