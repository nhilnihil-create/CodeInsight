#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    long long fb;
    fb = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((i % 3 == 0) && (i % 5 == 0))
        {
        }
        else if (i % 3 == 0)
        {
        }
        else if (i % 5 == 0)
        {
        }
        else
        {
            fb += i;
        }
    }

    cout << fb << endl;
    return 0;
}
