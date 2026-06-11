#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    vector<vector<P>> v;
    rep(i,n){
        int a;
        cin >> a;
        vector<P> t;
        rep(j,a){
            int x,y;
            cin >> x >> y;
            x--;
            t.emplace_back(x,y);
        }
        v.emplace_back(t);
    }
    int ans = 0;
    rep(ia,1<<n){
        bool f = true;
        int count = 0;
        rep(i,n){
            if(!(ia>>i & 1)) continue;
            rep(j,v.at(i).size()){
                int x = v.at(i).at(j).first;
                int y = v.at(i).at(j).second; 
                if((ia>>x & 1) != y){
                    f = false;
                    break;
                }
            }
            if(!f) break;
        }
        if(!f)continue;
        rep(i,n) if(ia>>i & 1) count++;
        ans = max(ans,count);
    }
    cout << ans << endl;
}