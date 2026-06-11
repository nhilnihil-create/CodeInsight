#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <climits>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

using int64 = long long;


int main() {
    int64 n;
    cin >> n;
    vector<int> a(n,0);
    for (int i=0; i<n; i++) cin >> a[i];
    int64 ans = 0;
    map<int64,int64> mp;
    for (int i=0; i<n; i++) {
       ans += mp[a[i]]++;
    }


    for (int i=0; i<n; i++) {
        cout << ans - mp[a[i]] + 1 << endl;
    }
}