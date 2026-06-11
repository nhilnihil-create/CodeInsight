#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>

signed main() {
    int n;
    cin >> n;
    vi a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    int ans = 0;
    for(auto& i : mp) {
        ans += ((i.second) * (i.second - 1)) / 2;
    }
    for(int i = 0; i < n; i++) {
        int curr = ans;
        int val = mp[a[i]];
        curr -= ((val) * (val - 1)) / 2;
        curr += ((val - 1) * (val - 2)) / 2;
        cout << curr << endl;
    }
}
