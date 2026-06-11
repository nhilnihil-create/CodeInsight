#include <iostream>
#include <cstdlib>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
 
int main(void)
{
    int N;
    cin >> N;

    int64_t a[100000];

    int64_t p = 1;
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];

        if (a[i] == 0)
        {
            cout << 0;
            return 0;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        if (a[i] <= 1000000000000000000/p) 
        {
            p *= a[i];
        }
        else
        {
            cout << (-1);
            return 0;
        }
    }
    
    cout << p;

    return 0;
}
