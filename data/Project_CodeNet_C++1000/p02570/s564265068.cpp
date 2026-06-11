#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//FILE *fi = freopen("1.txt", "r", stdin);
//FILE *fo = freopen("1", "w", stdout);
//FILE *fi = freopen("P.inp", "r", stdin);
//FILE *fo = freopen("P.out", "w", stdout);
int main()
{
    //------------------------------
    // Faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //-------------------------------
    int a, b, c;
    cin >> a >> b >> c;
    if (b * c >= a)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}