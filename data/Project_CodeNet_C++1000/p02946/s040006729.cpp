#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;

int main()
{
    int k, x;
    cin >> k >> x;
    for (int i = x - k + 1; i < x; i++)
        cout << i << " ";
    cout << x << " ";
    for (int i = x + 1; i < x + k; i++)
        cout << i << " ";
    return 0;
}
