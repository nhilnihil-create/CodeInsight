#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, count, i, j, k;
    long long l[100], tmp;
    count = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> l[i];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (l[i] < l[j])
            {
                tmp = l[i];
                l[i] = l[j];
                l[j] = tmp;
            }
        }
    }
    for (j = 0; j < n; j++)
    {
        for (k = 0; k < j; k++)
        {
            for (i = 0; i < k; i++)
            {
                if (l[i] != l[k] && l[k] != l[j])
                {

                    if (l[j] < l[i] + l[k])
                    {
                        count++;
                    }
                }
            }
        }
    }
    cout << count << endl;

    return 0;
}