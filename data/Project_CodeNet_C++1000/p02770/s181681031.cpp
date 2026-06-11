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
    int k, q;
    cin >> k >> q;
    vector<int> d(k);
    for(int i=0; i<k; ++i)
        cin >> d[i];

    while(--q >= 0){
        int n, x, m;
        cin >> n >> x >> m;
        -- n;

        long long sum = x % m;
        for(int i=0; i<k; ++i){
            int a = (n - i + k - 1) / k;
            int b = (d[i] + m - 1) % m + 1;
            sum += a * (long long)b;
        }
        long long ans = n - sum / m;
        cout << ans << endl;
    }

    return 0;
}
