
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n, k;
    cin >> n >> k;
    long option1, option2;
    option1 = n - n / k * k;
    option2 = abs(option1 - k);
    if(option1 > option2) cout << option2 << endl;
    else cout << option1 << endl;

    return 0;
}
