#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    string s; cin >> s;
    map<char, int> mp;
    for(char c: s){
        mp[c]++;
    }
    bool fg = true;
    if(mp.size()!=2)fg = false;
    for(auto m: mp) if(m.second != 2) fg = false;

    if(fg) cout << "Yes" << ln;
    else cout << "No" << ln;
    
}

