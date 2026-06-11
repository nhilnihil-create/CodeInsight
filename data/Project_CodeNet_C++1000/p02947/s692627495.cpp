#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    int n;
    cin >> n;
    map<string,ll> mp;
    rep(i,n){
        string s;
        cin >> s;
        vector<int> a(26);
        rep(j,10){
            a[s[j]-'a']++;
        }
        string t;
        rep(j,26) t.push_back('0'+a[j]);
        mp[t]++;
    }
    ll ans = 0;
    for(auto a : mp){
        ans += (a.second-1)*a.second/2;
    }
    cans;
    return 0;
}