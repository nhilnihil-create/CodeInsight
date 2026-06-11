//  ©   ___MRX___

#include <bits/stdc++.h>
    using namespace std;

#define ll long long int

int main()
{
    int n, i, j;
    string s;
    bool checker = true;

    cin >> n >> s;

    if(n % 2) {
        cout << "No" << '\n';
        return 0;
    }

    for(i = 0, j = n / 2; i < n / 2; i++, j++) {
        if(s[i] != s[j]) {
            checker = false;
            break;
        }
    }

    checker ? cout << "Yes" << '\n' : cout << "No" << '\n';

    return 0;
}
