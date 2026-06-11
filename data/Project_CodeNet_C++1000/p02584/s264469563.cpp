#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
#include <assert.h>
#include <cstring>
#include <set>

using namespace std;

typedef long long ll;

int main()
{
    ll x, k, d;
    cin >> x >> k >> d;

    if(x < 0)x = -x;

    if(x/d <= k)
    {
        k -= x/d;
        
        x = x-(x/d)*d;
        
        if(k%2 == 0)
        {
            cout << x;
            return 0;
        }
        else
        {
            cout << -(x-d);
            return 0;
        }
        
    }
    else
    {
        x = x-k*d;
        cout << x;
    }
    
}