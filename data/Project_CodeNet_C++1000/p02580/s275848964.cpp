#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;

template<typename T> bool chmax(T &a,const T b){if(a < b){a=b; return true;} return false;}
template<typename T> bool chmin(T &a,const T b){if(a > b){a=b; return true;} return false;}

int main(){
    int H, W, M; cin >> H >> W >> M;
    vi h(M), w(M);
    map<int, int> mph, mpw;
    set<pii> st;
    int hmaxval=0, wmaxval=0;
    for(int i=0; i<M; i++){
        cin >> h[i] >> w[i];
        h[i]--, w[i]--;
        chmax(hmaxval, ++mph[h[i]]);
        chmax(wmaxval, ++mpw[w[i]]);
        st.insert({h[i], w[i]});
    }

    vi hmax, wmax;
    for(auto p : mph){
        if(p.second == hmaxval) hmax.push_back(p.first);
    }
    for(auto p : mpw){
        if(p.second == wmaxval) wmax.push_back(p.first);
    }
    int ans=hmaxval+wmaxval-1;
    for(auto h : hmax){
        for(auto w : wmax){
            if(!st.count({h, w})){
                ans++;
                goto FIN;
            }
        }
    }
    FIN:
    cout << ans << endl;
    return 0;
}