#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <map>
#include <iomanip>
#include <stdio.h>
#include <bitset>

typedef long long LL;

constexpr long long INFLL = 1e18;

using namespace std;

int main()
{
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a.at(i);
    }

    for (int l = 0; l < k; l++)
    {
        vector<int> temp(n + 2, 0);
        for (int i = 1; i <= n; i++)
        {
            temp.at(max(0, i - a.at(i)))++;
            temp.at(min(n, i + a.at(i)) + 1)--;
        }
        for (int i = 1; i <= n; i++)
        {
            temp.at(i) += temp.at(i - 1);
        }
        if (a == temp)
        {

            break;
        }

        a = temp;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << a.at(i) << " ";
    }
    cout << endl;

    return 0;
}