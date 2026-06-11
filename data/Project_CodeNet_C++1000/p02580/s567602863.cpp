#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<int,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(void){

    int h, w, m;
    cin >> h >> w >> m;

    set<P> s; // setのfindの計算量はlog
    mp x, y;
    int hmval = 0, wmval = 0;
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        s.insert(P{a, b});
        x[a]++;
        y[b]++;
        chmax(hmval, x[a]);
        chmax(wmval, y[b]);
    }

    int ans = hmval + wmval - 1; // 爆弾が重複しているとしてマイナス1
    // 各行列ごとに、最大値と一致するhとwを答えの候補とする
    vector<int> hmax, wmax;
    for(auto q : x){
        if(hmval == q.second){
            hmax.push_back(q.first);
        }
    }
    for(auto q : y){
        if(wmval == q.second){
            wmax.push_back(q.first);
        }
    }

    // 答えの候補の中に重複しない（爆弾が存在しない）座標があれば、それが最大値となるからans+1をする
    for(auto q : hmax){
        for(auto p : wmax){
            if(s.find(P{q, p}) == s.end()){
                cout << ans + 1 << "\n";
                return 0;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
