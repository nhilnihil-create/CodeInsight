
#include <iostream>

using namespace std;

int main()
{
    int m, n_min, n_max;
    while (cin >> m >> n_min >> n_max, m)
    {
        int a[m] = {0};
        int gap[m] = {0};
        int MAX = 0;
        int MAX_n = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
            if (i > 0)
            {
                gap[i] = a[i - 1] - a[i];
            }
        }
        for (int i = n_min; i < n_max + 1; i++)
        {
            if (gap[i] >= MAX)
            {
                MAX = gap[i];
                MAX_n = i;
            }
        }
        cout << MAX_n << endl;
    }
}
