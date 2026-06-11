#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <bitset>
using namespace std;
typedef long long int lli;
int main(void)
{
    lli A, v;
    lli B, w;
    lli T;
    cin >> A >> v >> B >> w >> T;
    if (w >= v)
    {
        cout << "NO" << endl;
    }
    else
    {
        if (abs(A - B) <= T * (v - w))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
