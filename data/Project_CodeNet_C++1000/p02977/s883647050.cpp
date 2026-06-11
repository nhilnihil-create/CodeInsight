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
    if(bitset<32>(n).count() == 1){
        cout << "No" << endl;
        return 0;
    }

    vector<pair<int, int> > ans;
    ans.push_back(make_pair(1+n, 2+n));
    for(int a=2; a<n; a+=2){
        int b = a + 1;
        ans.push_back(make_pair(1, a));
        ans.push_back(make_pair(1, b));
        ans.push_back(make_pair(a, b+n));
        ans.push_back(make_pair(b, a+n));
    }
    if(n % 2 == 0){
        int a = 2;
        while((n & a) == 0)
            a <<= 1;
        int b = n ^ a ^ 1;
        ans.push_back(make_pair(a, n));
        ans.push_back(make_pair(b, n+n));
    }

    cout << "Yes" << endl;
    for(const auto& p : ans)
        cout << p.first << ' ' << p.second << endl;

    return 0;
}
