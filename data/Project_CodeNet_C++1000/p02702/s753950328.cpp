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
    int n = s.size();
    int fac = 1;
    map<int,int>mp;
    int ans = 0;
    mp[0] = 1;
    ll cur = 0;
    for(int i = 0;i<n;i++) {
        cur += (s[n-1-i]-'0')*fac;
        cur %= mod;
        ans += mp[cur];
        mp[cur]++;
        fac = fac*10%mod;
    }
    cout << ans << endl;
}
    


