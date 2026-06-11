#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cmath>
#include <functional>
#include <map>
#include <cstdlib>
#include <stack>
#include <cassert>

// aliases
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

// graph
using Graph = Vvec<int>;
class Edge{
public:
    int to;
    long long cost;
    Edge(int v, long long c = 1): to(v), cost(c){}
    ~Edge(){}
    bool operator<(const Edge& e) const{return cost < e.cost;}
};
using WeightedGraph = Vvec<Edge>;

// for debug
template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

ll count(int& e, vector<int>& v){
    ll ret = 0;
    for(auto& f: v){
        if(e == f) ret++;
    }
    return ret;
}

// answer
int main()
{
    constexpr ll sz = 3e5+3;
    int H, W, M;
    cin >> H >> W >> M;
    vector<int> h(M), w(M), ch(sz), cw(sz);
    for(int i=0; i<M; i++){
        cin >> h[i] >> w[i];
        ch[h[i]]++;
        cw[w[i]]++;
    }

    int mh = *max_element(ch.begin(), ch.end());
    int mw = *max_element(cw.begin(), cw.end());
    ll c = count(mh, ch) * count(mw, cw);

    for(int i=0; i<M; i++){
        if(ch[h[i]] == mh && cw[w[i]] == mw){
            c--;
        }
    }
    
    cout << ((c == 0) ? mh+mw-1 : mh+mw) << "\n";
}