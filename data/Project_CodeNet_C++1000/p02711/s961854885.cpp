#include <bits/stdc++.h>

using namespace std;

int main()
{  int n, a, b, c;
    cin >> n;
    if ((n <= 999) && (n >= 100))
    {
    a = n % 10;
    n = n - a;
    b = n / 100;
    n = n - (b * 100);
    c = n / 10;
    if ((a == 7) || (b == 7) || (c == 7))
        cout << "Yes";
    else
        cout << "No";
    }
}



