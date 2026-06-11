#include <bits/stdc++.h>
#include <atcoder/dsu>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define fi first
#define se second
const long INF = 1e15;
using namespace std;
using namespace atcoder;

template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class T>
inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T>
inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout<<fixed<<setprecision(20);

    int N,Q; cin >> N >> Q;
    dsu d(N);
    rep(i,Q) {
        int t,u,v;
        cin >> t >> u >> v;
        if(t) {
            if(d.same(u,v)){
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else {
            d.merge(u,v);
        }
    }
}