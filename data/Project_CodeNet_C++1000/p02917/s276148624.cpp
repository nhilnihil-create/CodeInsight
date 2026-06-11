#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll n, c;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }
    c = arr[0] + arr[n - 1 - 1];
    for (int i = 0; i < n - 1 - 1; i++)
    {
        c += min(arr[i], arr[i + 1]);
    }
    cout << c << endl;
}