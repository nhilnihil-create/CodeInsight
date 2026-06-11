#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n;
    cin>>n;
    ll a;
    cin>>a;
    ll res = 0, h = a;
    for (int i=1; i<n; i++) {
        cin>>a;
        if (a > h) h = a;
        else res += (h - a);
    }
    cout << res << '\n';
    return 0;
}