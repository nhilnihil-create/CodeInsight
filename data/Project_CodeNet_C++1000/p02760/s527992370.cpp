#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cctype>
#include <map>
#include <set>

const int INT_INF = 1e9;
const long long LONG_INF = 1e18;
const long long MOD = 1e9 + 7;
const double PI = 3.14159265358979323846;

using namespace std;

int main()
{
    int len = 9;
    vector<pair<int, bool>> a(len);
    for (int i = 0; i < len; i++)
    {
        cin >> a[i].first;
        a[i].second = false;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        for (int j = 0; j < len; j++)
        {
            if (b == a[j].first)
            {
                a[j].second = true;
                break;
            }
        }
    }
    /*
        0 1 2
        3 4 5
        6 7 8
    */
    if (a[4].second)
    {
        if (a[0].second && a[8].second || a[1].second && a[7].second || a[2].second && a[6].second || a[3].second && a[5].second)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    if (a[0].second)
    {
        if (a[1].second && a[2].second || a[3].second && a[6].second)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    if (a[8].second)
    {
        if (a[6].second && a[7].second || a[2].second && a[5].second)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}