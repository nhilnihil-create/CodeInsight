#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int zoro = 0;
    int i = 0;
    while (zoro != 3 && i < n)
    {
        int left, right;
        cin >> left >> right;
        if (left == right)
        {
            zoro++;
        }
        else
            zoro = 0;
        i++;
    }
    if (zoro >= 3)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}