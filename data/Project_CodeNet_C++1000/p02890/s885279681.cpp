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
    map<int, int> cnt;
    for(int i=0; i<n; ++i){
        int a;
        cin >> a;
        ++ cnt[a];
    }

    vector<int> v;
    for(const auto& p : cnt)
        v.push_back(p.second);
    sort(v.rbegin(), v.rend());
    int m = v.size();

    int i = 0;
    int x = 1;
    int y = n;
    int sum = n;
    for(int k=1; k<=n; ++k){
        while(y > 0 && x < k){
            -- y;
            if(y == 0){
                x = 0;
                break;
            }
            while(i < m && v[i] > y)
                ++ i;
            sum -= i;
            x = sum / y;
        }
        cout << y << endl;
    }

    return 0;
}
