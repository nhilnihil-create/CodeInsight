#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;

int ans[N];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int x  = 1;
    map<int, int> mp;
    mp[0] = 1;
    ll res = 0;
    for(int i = n - 1; i >= 0; i--){
        ans[i] = (x * (s[i] - '0') + ans[i + 1]) % 2019;
        // cout << ans[i] << ' ';
        x = (x * 10) % 2019;
        res += mp[ans[i]];
        mp[ans[i]]++;
    }
    cout << res;

    return 0;
}
