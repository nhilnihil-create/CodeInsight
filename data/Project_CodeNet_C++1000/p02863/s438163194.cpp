#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
using namespace std;


int main(){
    long long n, t;
    cin >> n >> t;
    vector<pair<long long, long long> > a(n);
    for(int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end());
    
    vector<long long> d(t, -1e9);
    d[0] = 0;

    long long ans = 0;
    for(int i = 0; i < n; ++i)
        for(int j = t - 1; j >= 0; --j){
            if(d[j] == -1e9) continue;
            ans = max(ans, d[j] + a[i].second);
            if(j + a[i].first < t) d[j + a[i].first] = max(d[j + a[i].first], d[j] + a[i].second);
        }
    cout << ans;
}
