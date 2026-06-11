#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int mod = 1000000007;

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s.at(i);
    vector<vector<int>> cnt(h,vector<int>(w,0));
    rep(i,h){
        vector<int> done(w);
        rep(j,w){
            if(s.at(i).at(j) == '#')continue;
            if(done.at(j)) continue;
            int l = 0;
            while(j+l < w){
                if(s.at(i).at(j+l) == '#')break;
                l++;
            }
            rep(k,l){
                cnt.at(i).at(j+k) += l;
                done.at(j+k) = 1;
            }

        }
    }
    rep(j,w){
        vector<int> done(h);
        rep(i,h){
            if(s.at(i).at(j) == '#')continue;
            if(done.at(i)) continue;
            int l = 0;
            while(i+l < h){
                if(s.at(i+l).at(j) == '#')break;
                l++;
            }
            rep(k,l){
                cnt.at(i+k).at(j) += l;
                done.at(i+k) = 1;
            }

        }
    }
    int ans = 0;
    rep(i,h)rep(j,w) ans = max(ans,cnt.at(i).at(j) -1);
    cout << ans << endl;
    return 0;
}