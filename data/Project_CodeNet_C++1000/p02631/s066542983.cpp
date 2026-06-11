#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define max 1000000
int main()
{
    int n;
    cin >> n;
    ll a[n + 5] = {0};
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum = (sum ^ a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << (sum ^ a[i]) << " ";
    }
    return 0;
}
