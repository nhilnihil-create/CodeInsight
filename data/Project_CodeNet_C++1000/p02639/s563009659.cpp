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
    int x[5];
    cin >> x[0] >> x[1] >> x[2] >> x[3] >> x[4];

    for (int i = 0; i < 5; ++i)
    {
        if (x[i] == 0)
        {
            cout << (i+1) << endl;
            break;
        }
    }

    return 0;
}
