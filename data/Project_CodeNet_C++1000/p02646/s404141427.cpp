#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

#define DEBUG_ENABLED 0
typedef long long int ll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll A, V, B, W, T;
    cin >> A >> V;
    cin >> B >> W;
    cin >> T;

    bool caught = false;

    ll velocity_diff = (V - W);
    if (DEBUG_ENABLED)
        cout << velocity_diff << endl;
    if (velocity_diff > 0)
    {
        // oni velocity is greater than sheep
        ll diff = (B - A > 0) ? (B - A) : (A - B);

        if (DEBUG_ENABLED)
            cout << diff << endl;

        if (diff <= velocity_diff * T)
        {
            caught = true;
        }
    }

    if (caught)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
