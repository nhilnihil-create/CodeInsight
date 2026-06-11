#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void) {
    int n; cin >> n;
    vector<pair<int64_t, int64_t>> ranges(n);

    for(int i = 0; i < n; ++i) {
        int64_t x, l; cin >> x >> l;
        ranges[i].first = x - l;
        ranges[i].second = x + l;
    }

    sort(ranges.begin(),
         ranges.end(),
         [](pair<int64_t, int64_t> x, pair<int64_t, int64_t> y) {
             if(x.second == y.second) return x.first < y.first;
             else return x.second < y.second;
         }
    );

    int ans = 1;
    int pos = ranges[0].second;
    for(int i = 1; i < n; ++i) {
        if(ranges[i].first < pos) continue;
        ans++;
        pos = ranges[i].second;
    }
    cout << ans << endl;


    return 0;
}
