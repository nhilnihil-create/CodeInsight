#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];  
    map<int,int> mp;
    ll ans=0;
    for(int i = 0; i < n; i++) {
        int l=i+a[i];
        int r=i-a[i];
        ans += mp[r];
        mp[l]++;
    }
    cout << ans << endl;


    return 0;
}