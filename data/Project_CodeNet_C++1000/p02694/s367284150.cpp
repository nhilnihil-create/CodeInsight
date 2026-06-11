#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int x, i = 0;
    cin >> x;
    long long int p = 100;
    for (; p < x; i++)
    {
        p += p / 100;
    }
    cout << i;
}