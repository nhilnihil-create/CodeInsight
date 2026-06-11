#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    vector<pair<int, int>> ans;

    for (int i = 1; i < n - 1; i++){
        if(a[i] > 0){
            ans.emplace_back(a[0], a[i]);
            a[0] -= a[i];
        } else {
            ans.emplace_back(a[n - 1], a[i]);
            a[n - 1] -= a[i];
        }
    }
    ans.emplace_back(a[n - 1], a[0]);
    cout << a[n - 1] - a[0] << endl;
    for(auto p : ans){
        cout << p.first << " " << p.second << endl;
    }
}