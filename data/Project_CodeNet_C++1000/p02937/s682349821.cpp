#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    ll ans = 0, n = s.size(), m = t.size();
    map<char, ll> mps;
    vector<set<int>> st(26);
    rep(i, n){
        mps[s[i]]++;
        st[s[i]-'a'].insert(i+1);
    }
    bool ok = true;
    rep(i, t.size())if(!mps[t[i]])ok = false;
    if(ok){
        rep(i, m){
            auto it1 = st[t[i]-'a'].upper_bound(ans%n);
            if(it1 == st[t[i]-'a'].end()){
                ans += n-(ans%n);
                auto it2 = st[t[i]-'a'].begin();
                ans += *it2;
            }
            else{
                ans += *it1 - (ans%n);
            }
        }
    }
    cout << (ok ? ans : -1) << endl;
}   