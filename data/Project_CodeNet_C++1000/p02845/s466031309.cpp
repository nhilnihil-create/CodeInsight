#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

constexpr i64 MOD = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;++i){
        int a;
        cin >> a;
        v.push_back(a);
    }
    i64 ans = 1;
    map<i64, i64> mp;
    mp[-1] = 3;
    for(int i=0;i<n;++i){
        ans *= mp[v[i]-1];
        ans %= MOD;
        mp[v[i]-1]--;
        mp[v[i]]++;
    }

    cout << ans << endl;

    return 0;
}