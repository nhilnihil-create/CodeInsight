#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <string>
#define ll long long
#include <vector>
using std::vector;

using namespace std;


int main()
{
    ll a , b;
    cin >> a >> b;
    if((a+b)%2 == 0)
        cout << (a+b)/2 << endl;
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}
