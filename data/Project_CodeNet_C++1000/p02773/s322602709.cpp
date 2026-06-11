#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
using VVI = vector<vector<long long int> >;

int main(void) {
    Int n;
    cin >> n;
    map<string, Int> mp;

    string s;
    for (Int i = 0 ; i < n; ++i) {
        cin >> s;
        ++mp[s];
    }
    vector<pair<Int, string> > v;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        v.push_back(make_pair(itr->second, itr->first));
    }

    sort(v.begin(), v.end());

    Int vec_size = (Int)v.size();

    Int max_times = v[vec_size - 1].first;
    for (Int i = 0; i < v.size(); ++i) {
        if (v[i].first == max_times) {
            cout << v[i].second << endl;
        }
    }
    return 0;
}

