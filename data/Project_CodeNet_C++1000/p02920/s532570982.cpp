#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P>IP;
typedef vector<ll> V;
typedef vector<V> V2;
typedef vector<vector<P> > G;
void g_dir(G &graph, ll a, ll b, ll w = 1){graph[a].push_back(P(b, w));}
void g_undir(G &graph, ll a, ll b, ll w = 1){g_dir(graph, a, b, w);g_dir(graph, b, a, w);}
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}
const ll INF = 1145141919;
const ll MOD = 1000000007;
const ll NUM = 101010;
template<class T> T miman_max(set<T> &S, const T &x){
    typename set<T>::iterator it = S.lower_bound(x);
    it--;
    return *it;
}
template<class T> T maximum_from_set(set<T> &S){
    typename set<T>::iterator it = S.end();
    it--;
    return *it;
}
int main(){

    ll N;
    cin >> N;
    set<P>S;
    S.insert(P(-1, -1));
    rep(i, 1 << N){
        ll x;
        cin >> x;
        S.insert(P(x, i));
    }
    V v;
    v.push_back(maximum_from_set(S).first);
    S.erase(maximum_from_set(S));
    rep(i, N){
        V w;
        rep(j, v.size()){
            P p = miman_max(S, P(v[j], 0));
            if(p.first == -1){
                cout << "No" << endl;
                return 0;
            }
            S.erase(p);
            w.push_back(v[j]);
            w.push_back(p.first);
        }
        swap(v, w);
    }
    cout << "Yes" << endl;
    return 0;
}