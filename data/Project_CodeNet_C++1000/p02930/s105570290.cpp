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

    vector<vector<int> > a(n, vector<int>(n, 1));
    for(int x=0; x<n; ++x){
        for(int y=x+1; y<n; ++y){
            int z = x ^ y;
            while(!(z & 1)){
                ++ a[x][y];
                z >>= 1;
            }
        }
    }

    for(int x=0; x<n-1; ++x){
        cout << a[x][x+1];
        for(int y=x+2; y<n; ++y)
            cout << ' ' << a[x][y];
        cout << endl;
    }

    return 0;
}
