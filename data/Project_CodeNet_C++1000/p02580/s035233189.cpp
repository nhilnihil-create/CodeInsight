#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int h,w,m;
    cin >> h >> w >> m;
    set<pair<int,int>> st;//爆破対象を記録
    map<int,int> mph,mpw;
    int maxh = 0;
    int maxw = 0;
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        mph[a]++;//ある行の爆破物の個数をカウント
        mpw[b]++;//ある列の爆破物の個数をカウント
        //爆破物の個数が最大の行と列の個数を更新
        chmax(maxh,mph[a]);
        chmax(maxw,mpw[b]);
        st.insert({a,b});
    }
    //最大行と最大列の座標を記録
    vector<int>H,W;
    for(auto tmp : mph) {
        if(tmp.second==maxh) H.push_back(tmp.first);
    }
    for(auto tmp : mpw) {
        if(tmp.second == maxw) W.push_back(tmp.first);
    }
    int ans = maxh+maxw-1;
    for(auto i : H) {
        for(auto j: W) {
            //最大行と最大列の座標が見つからないとき
            //つまり爆破するマスに爆破物がない
            if(st.find({i,j})==st.end()) {
                ans++;
                cout << ans << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    

}