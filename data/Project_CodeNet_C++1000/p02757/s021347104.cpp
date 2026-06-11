#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


int main() {
    ll n,p;
    cin >> n >> p;
    const int mod = p;
    string s;
    cin >> s;
    ll ans = 0;
    if(p==2 || p==5) {
        rep(i,n) if((s[n-1-i]-'0')%p == 0) ans += n-i; 
        cout << ans << endl;
        return 0;   
    }
    ll cur = 0;
    ll fac = 1;
    vector<int>d(n+1);  
    for(int i = n-1;i>=0;i--) {
        cur = (s[i]-'0')*fac;
        cur %= mod;
        d[i] = (d[i+1] + cur)%mod;
        fac = fac*10%mod;
    }
    vector<int>cnt(p);
    for(int i = n;i>=0;i--) {
        ans += cnt[d[i]];
        cnt[d[i]]++;
    }
    cout << ans << endl;
}
    


