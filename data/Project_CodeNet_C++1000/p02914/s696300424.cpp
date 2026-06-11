#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
#include <memory>
#include <regex>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    long long y = 0;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        y ^= a[i];
    }
    for(int i=0; i<n; ++i)
        a[i] &= ~y;

    long long x = 0;
    for(int i=62; i>=0; --i){
        long long tmp = 0;
        for(int j=0; j<n; ++j){
            if(a[j] & (1LL << i)){
                tmp = a[j];
                break;
            }
        }

        if(!(x & (1LL << i)))
            x ^= tmp;
        for(int j=0; j<n; ++j){
            if(a[j] & (1LL << i))
                a[j] ^= tmp;
        }
    }

    y ^= x;
    long long ans = x + y;
    cout << ans << endl;

    return 0;
}
