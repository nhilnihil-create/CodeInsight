#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
 
int main(){
    int H, W, M;
    cin >> H >> W >> M;
    typedef pair<int, int> pair_items;
    set<pair_items> st;
    REP(i,M){
        int a, b;
        cin >> a >> b;
        st.insert({a, b});
    }
    map<int, int> mph, mpw;
    int hmax_value = 0;
    int wmax_value = 0;
    
    for(auto tmp: st){
        chmax(hmax_value, ++mph[tmp.first]);
        chmax(wmax_value, ++mpw[tmp.second]);
    }
 
    vector<int> h_maxes, w_maxes;
 
    for(auto h_item: mph){
        if(h_item.second == hmax_value){
            h_maxes.push_back(h_item.first);
        }
    }
 
    for(auto w_item: mpw){
        if(w_item.second == wmax_value){
            w_maxes.push_back(w_item.first);
        }
    }
 
    for(auto hval: h_maxes){
        for(auto wval : w_maxes){
            if(st.find({hval, wval})==st.end()){
                cout << hmax_value + wmax_value << endl;
                return 0;
            }
        }
    }
    cout << hmax_value + wmax_value - 1 << endl;
    return 0;
 
}