#include<bits/stdc++.h>
using namespace std;

main()
{
    int co_ordinate, sum = 0, MINIMUM_SUM = 999999;

    cin >> co_ordinate;

    int values[co_ordinate];

    for (int i = 0; i < co_ordinate; i++)
    {
        cin >> values[i];
    }

    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < co_ordinate; j++)
        {
            sum = sum + (values[j] - i) * (values[j] - i);
        }

        MINIMUM_SUM = min(MINIMUM_SUM, sum);
        sum = 0;
    }

    cout << MINIMUM_SUM;

}