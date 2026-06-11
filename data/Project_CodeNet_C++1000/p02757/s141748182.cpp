#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;

int ans[N];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, p;
    string s;
    cin >> n >> p >> s;
    if(p == 2){
        ll res = 0;
        for(int i = 0; i < n; i++){
            if((s[i] - '0') % 2 == 0){
                res += (i + 1);
            }
        }
        return cout << res, 0;
    }
    if(p == 5){
        ll res = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0' || s[i] == '5'){
                res += (i + 1);
            }
        }
        return cout << res, 0;
    }
    int x = 1;
    for(int i = n - 1; i >= 0; i--){
        ans[i] = (x * (s[i] - '0') + ans[i + 1]) % p;
        x = (x * 10) % p;
    }
    map<int, ll> mp;
    mp[0] = 1;
    ll res = 0;
    for(int i = n - 1; i >= 0; i--){
        res += mp[ans[i]];
        mp[ans[i]]++;
    }
    cout << res;


    return 0;
}
