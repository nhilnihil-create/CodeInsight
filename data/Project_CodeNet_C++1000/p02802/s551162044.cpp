#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,string>;
const int INF = 1001001001;

int main(){
    int n,m;
    cin >> n >> m;
    vector<P> r;
    rep(i,m){
        int p;string s;
        cin >> p >> s;
        p--;
        r.emplace_back(p,s);
    }
    vector<bool> ac(n,false);
    vector<int> wa(n,0);
    for(auto x : r){
        int p = x.first;
        string s = x.second;
        if(ac.at(p)) continue;
        else if(s == "AC") ac.at(p) = true;
        else wa.at(p)++;
    }
    int ans_ac = 0;
    int ans_wa = 0;
    for(auto x : ac) if(x) ans_ac++;
    for(int i = 0;i < n;++i) if(ac.at(i)) ans_wa +=wa.at(i);
    cout << ans_ac << " " << ans_wa << endl;
}