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
    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin >> a[i];
    sort(a.rbegin(), a.rend());

    long long ans = 0;
    for(int i=0; i<n-1; ++i)
        ans += a[(i+1)/2];
    cout << ans << endl;

    return 0;
}
