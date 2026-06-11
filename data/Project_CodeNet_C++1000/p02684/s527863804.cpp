#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
#define rep(i,n) for(ll i = 0; i < (ll)(n); ++i)
 
constexpr double PI = acos(-1);
int alre[1000000];
int main() {
    ll n,k;
    cin >> n >> k;
    vector<int> g(n+1,0);
    int a;
    rep(i,n) {
        cin >> a;
        g.at(i+1) = a;
    }
    vector<int> log;
    int nowPos;
    nowPos = 1;
    log.emplace_back(1);
    ll s,e,flag,loop;
    s = e = flag = loop = 0;
    rep(i,k+1) {
        int ii = i + 1;
        nowPos = g.at(nowPos);
        log.emplace_back(nowPos);
        if(flag == 0 && alre[nowPos]) {
            s = ii;
            flag++;
        } else if(flag == 1 && log.at(ii)==log.at(s)) {
            flag++;
            e = ii;
            loop = (k-s)%(e-s);
            break;
        }
        alre[nowPos]=1;
    }
    if(loop==0 && flag<2) {
        cout << log.at(k) << "\n";
        return 0;
    }
    nowPos = log.at(s+loop);
    cout << nowPos << "\n";
    return 0;
}