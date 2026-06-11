#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int l, r; cin >> l >> r;
    if(r - l >= 2025) return cout << 0, 0;
    vector<int> v;
    int ans = 1e9;
    for(int i = l; i <= r; i++) v.push_back(i % 2019);
        
    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            ans = min(ans, (v[i] * v[j]) % 2019);
        }
    }
    cout << ans;
}