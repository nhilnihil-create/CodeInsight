#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<long long, long long>> v;
    for(int i = 0; i < n; i++){
        long long x, y;
        cin >> x >> y;
        v.emplace_back(x, y);
    }
    sort(v.rbegin(), v.rend());
    map<pair<long long, long long>, int> cnt;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            pair<long long, long long> p;
            p.first = v[i].first - v[j].first;
            p.second = v[i].second - v[j].second;
            cnt[p]++;
        }
    }
    int ans = 0;
    for(auto p : cnt){
        ans = max(ans, p.second);
    }
    ans = n - ans;
    cout << ans << endl;
    return 0;
}