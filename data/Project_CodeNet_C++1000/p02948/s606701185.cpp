#include <bits/stdc++.h>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr int INF = 1001001001;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<P, vector<P>, greater<P>> p;
    rep (i, n) {
        int a, b;
        cin >> a >> b;
        p.emplace(a, b);
    }
    
    ll ans = 0;
    priority_queue<int> q;
    rep (i, 1, m+1) {
        while(!p.empty()) {
            auto r = p.top();
            if (r.first == i) {
                q.push(r.second);
                p.pop();
            }
            else
                break;
        }
        if (!q.empty()) {
            ans += q.top();
            q.pop();
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
