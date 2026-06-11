#include<bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
using namespace atcoder;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


int main() {
    int n,m;
    cin >> n >> m;
    dsu uf(n);
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        uf.merge(a,b);
    }
    set<int>se;
    rep(i,n) se.insert(uf.leader(i));
    int ans = se.size()-1;
    cout << ans << endl;
}