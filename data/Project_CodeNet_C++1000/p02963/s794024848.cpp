#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t s; cin >> s;
    const int64_t limit = 1e9;
    vector<pair<int64_t, int64_t>> x(3, {0, 0});
    x[1].first = limit; x[1].second = 1;
    x[2].second = (s + limit - 1) / limit;
    x[2].first = (limit * x[2].second - s) % limit;
    for (auto & elm : x) cout << elm.first << " " << elm.second << " ";
    cout << endl;
    return 0;
}