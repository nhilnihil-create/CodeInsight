#include <cstdio>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

int main()
{
    for(;;){
        int n, m;
        cin >> n >> m;
        if(n == 0)
            return 0;

        vector<pair<int, int> > a(n);
        for(int i=0; i<n; ++i)
            cin >> a[i].second >> a[i].first;
        sort(a.rbegin(), a.rend());

        int ret = 0;
        for(int i=0; i<n; ++i){
            ret += max(0, a[i].second - m) * a[i].first;
            m -= min(m, a[i].second);
        }
        cout << ret << endl;
    }
}