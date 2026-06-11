#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ch;
    cin >> n;

    ch = ((n / 1000 + 1) * 1000 - n) % 1000;

    cout << ch << endl;
    return 0;
}