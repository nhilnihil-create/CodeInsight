#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

const int mxN = 2e5;

int main()
{
    ll n, a[mxN], tot = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        tot ^= a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << (tot^a[i]) << " ";
    }
}