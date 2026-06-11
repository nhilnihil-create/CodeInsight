#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;


int main(){
    int n,k;
    cin >> n >> k;
    vector<ll>a(n);
    rep(i,n){
        cin>>a[i];
        a[i]--;
    }
    vector<ll>s(n+1,0);
    rep(i,n){
        s[i+1]=(s[i]+a[i])%k;
    }
    queue<ll>q;
    ll cnt = 0;
    map<int,int>mp;
    for(int j=0;j<=n;j++){
        ll now = s[j];
        cnt += mp[now];
        q.push(now);
        mp[now]++;
        if(q.size()==k){
            ll e = q.front();q.pop();
            mp[e]--;
        }
    }
    cout << cnt << endl;
    return 0;
}