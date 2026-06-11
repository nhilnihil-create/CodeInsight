#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t=0;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++)
    {
        cin >> a[n];
        if (a[n] % 2 != 0 && (i+1) % 2 != 0)
            t++;
    }
    cout << t;
    return 0;
}
