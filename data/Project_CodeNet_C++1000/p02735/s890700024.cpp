#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

const int INF = 1e9;
int h,w;
vector<vector<char>> v(100);

int main(){
    cin >> h >> w;
    
    rep(i,h){
        vector<char> r(w);
        rep(j,w){
            cin >> r.at(j);
        }
        v.at(i) = r;
    }

    // rep(i,h)
    // {
    //     rep(j,w){
    //         cout << v.at(i).at(j);
    //     }
    //     cout << endl;
    // }
    
    vector<vector<int>> dp(h);
    rep(i,h)
    {
        vector<int> r(w);
        dp.at(i) = r;
    }

    rep(i,h)
    {
        rep(j,w){
            char cur = v.at(i).at(j);
            int ra = INF,rb = INF;
            if(i==0 && j == 0){
                if(v.at(0).at(0) == '#') ra = 1;
                else ra = 0;
            }
            if(j > 0){
                ra = dp.at(i).at(j-1);
                if(cur == '#' && v.at(i).at(j-1) == '.'){
                    ra++;
                }
            }
            if(i > 0){
                rb = dp.at(i-1).at(j);
                if(cur == '#' && v.at(i-1).at(j) == '.'){
                    rb++;
                }
            }
            dp.at(i).at(j) = min(ra,rb);
        }
    }

    cout << dp.at(h-1).at(w-1) << endl;

    return 0;
}