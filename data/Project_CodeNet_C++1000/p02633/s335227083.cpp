#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;

const unsigned long long BASE = (unsigned long long)(1e9 + 7);

#define FROM_0(i, n) for(int i = 0; i < (n); i++)
#define FROM_S(i, s, e) for(int i = (s); i < (e); i++)
#define ITER_BEGIN_END(iter, vec) for(auto iter = vec.begin(); iter < vec.end(); iter++)


int gcd(int x, int y)
{
    if (y > x)
        std::swap(x, y);
    while (y > 0)
    {
        int t = x % y;
        x = y;
        y = t;
    }
    return x;
}


int main()
{
    int x;
    cin >> x;
    int g = gcd(x, 360);
    int all = x * 360 / g;
    cout << all / x << endl;

    return 0;
}
