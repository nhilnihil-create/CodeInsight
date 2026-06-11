#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <functional>
#define _LIBCPP_DEBUG 0
using namespace std;

long long gcd(long long a, long long b)
{
    if (a % b == 0)
    {
        return (b);
    }
    else
    {
        return (gcd(b, a % b));
    }
}

int main(void){
    long long a,b;
    cin >> a >> b;
    long long gcd_num=gcd(a,b);
    cout << a*b/gcd_num << endl;

}
