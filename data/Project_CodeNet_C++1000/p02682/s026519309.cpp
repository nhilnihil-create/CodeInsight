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
    int64_t A, B, C, K;
    cin >> A >> B >> C >> K;

    if (A>=K)
    {
        cout << K;
    }
    else if (A + B >= K)
    {
        cout << A;
    }
    else {
        cout << (A - (K - (A + B)));
    }

    return 0;
}
