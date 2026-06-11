#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define debug(v) cout << #v<< ": " << v <<endl;
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;
ll INF = 1LL<<60;
ll M = 1000000007;

int main(){
    string s,t; cin >> s >> t;
    ll n = sz(s), mm = sz(t);
    set<char> S, T;
    rep(i, 0, n){
        S.insert(s[i]);
    }
    rep(i, 0, mm){
        T.insert(t[i]);
    }
    bool b = true;
    for(auto x: T){
        if(S.find(x) == S.end()){
            b = false;
        }
    }
    if(!b){
        prtl(-1);
    }else{
        map<char, vll> m;
        rep(i, 0, n){
            if(m.find(s[i]) == m.end()){
                vll h(0);
                h.emplace_back(i);
                m[s[i]] = h;
            }else{
                m[s[i]].emplace_back(i);
            }
        }
        ll p = -1;
        ll c = 0;
        rep(i, 0, mm){
            char k = t[i];
            if(upper_bound(m[k].begin(), m[k].end(), p) == m[k].end()){
                p = m[k][0];
                c++;
            }else{
                p = *upper_bound(m[k].begin(), m[k].end(), p);
            }
        }
        prtl(n*c+p+1);
    }   
}

