#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, k, x;
    vector<ll> nums(1,0);
    cin >> n >> k;
    vector<bool> visited(n+1,0);
    for (ll i=0; i<n; i++) {
        cin >> x;
        nums.push_back(x);
    }
    x = 1;
    vector<ll> path, path2;
    while (!visited[x]) {
        visited[x] = true;
        path.push_back(x);
        x = nums[x];
    }
    ll y = x;
    path2.push_back(y);
    y = nums[y];
    while (y!=x) {
        path2.push_back(y);
        y = nums[y];
    }
    if (k<path.size()) cout << path[k];
    else {
        k-=(path.size()-path2.size());
        cout << path2[k%path2.size()];
    }
    return 0;
}