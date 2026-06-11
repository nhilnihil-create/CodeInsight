#include <cstring>
#include <iostream>
using namespace std;
int n, m, sum;
int main()
{
    cin >> n >> m >> sum;
    for (int i = 1; i <= m; i++)
    {
        cout << sum << " ";
    }
    int temp = n - m;
    for (int i = 1; i <= temp; i++)
    {
        if (sum == 1e9)
        {
            cout << sum - 1 << " ";
        }
        else
            cout << sum + 1 << " ";
    }
    return 0;
}