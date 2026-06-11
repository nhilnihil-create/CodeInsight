#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

const int mod = 2019;
int main() {
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    map<int,int>mp;
    mp[0] = 1;
    int cur = 1;
    ll ans = 0;
    int x = 0;
    rep(i,s.size()) {
        x += (s[i]-'0')*cur;
        x %= mod;
        ans += mp[x];
        mp[x]++;
        cur *= 10;
        cur %= mod;
    }
    cout << ans << endl;
}