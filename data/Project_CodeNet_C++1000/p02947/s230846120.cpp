#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
int main() {
    int n; cin >> n;
    vector<string> str(n);
    unordered_map<string, ll> um;
    rep(i, n) cin >> str.at(i);
    ll count = 0;
    rep(i, n){
        sort(str.at(i).begin(), str.at(i).end());
        um[str.at(i)] += 1;
        count += (um[str.at(i)] - 1);
    }
    cout << count << endl;
    return 0;
}