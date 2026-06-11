#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e16;

int main(){
    string s,t;
    cin >> s >> t;
    vector<vector<ll>>num(26);
    ll ls = s.size();
    ll lt = t.size();
    rep(i,ls){
        ll now = s[i]-'a';
        num[now].push_back(i);
        num[now].push_back(i+ls);
    }
    rep(i,26){
        sort(num[i].begin(),num[i].end());
    }
    ll ans = 0;
    ll pos = 0;
    rep(i,lt){
        ll now = t[i]-'a';
        if(num[now].size()==0){
            cout << -1 << endl;
            return 0;
        }
        ll nx = *lower_bound(num[now].begin(),num[now].end(),pos)+1;
        if(nx>=ls){
            ans+=nx-pos;
            pos=nx-ls;
        }
        else{
            ans+=nx-pos;
            pos = nx;
        }
    }
    cout << ans << endl;
    return 0;
}

