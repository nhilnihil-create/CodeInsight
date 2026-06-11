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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin >> a[i];

    int left = 1;
    int right = *max_element(a.begin(), a.end());
    while(left < right){
        int mid = (left + right) / 2;
        int cnt = 0;
        for(int i=0; i<n; ++i)
            cnt += (a[i] - 1) / mid;

        if(cnt <= k)
            right = mid;
        else
            left = mid + 1;
    }
    cout << left << endl;

    return 0;
}
