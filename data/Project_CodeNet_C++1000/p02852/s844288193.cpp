#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

llong n;
llong m;
string s;
vector<llong> p;
vector<llong> ans;

int main() {
    cin >> n >> m;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') p.push_back(i);
    }
    
    llong idx = n;
    while (idx > 0) {
        auto itr = upper_bound(p.rbegin(), p.rend(), idx - m, greater<>());
        
        itr--;
        if (idx == *itr) {
            cout << -1 << endl;
            return 0;
        }
        
        ans.push_back(idx - *itr);
        idx = *itr;
        while (idx < p.back()) p.pop_back();
    }

    reverse(ans.begin(), ans.end());
    for (auto v:ans) {
        cout << v << ' ';
    }
    cout << endl;

    return 0;
}
