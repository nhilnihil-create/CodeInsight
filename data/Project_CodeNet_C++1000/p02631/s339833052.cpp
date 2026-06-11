#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
int a[maxn];

int main()
{
    int n;
    cin >> n;
    cin >> a[0];
    int xr = a[0];
    for(int i=1; i<n; i++) {
        cin >> a[i];
        xr = a[i]^xr;
    }

    for(int i=0; i<n; i++) cout << (a[i]^xr) << " ";
    cout << "\n";

    return 0;
}