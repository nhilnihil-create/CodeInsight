#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    cout << floor(log10(n) / log10(k)) + 1;

    return 0;
}