#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()


int main(){
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    REP(i, h){
        cin >> s.at(i);
    }

    const bool start_is_black = s.at(0).at(0) == '#';
    const bool end_is_black = s.at(h - 1).at(w - 1) == '#';
    if(start_is_black){
        REP(i, h){
            REP(j, w){
                if(s.at(i).at(j) == '#'){
                    s.at(i).at(j) = '.';
                }else{
                    s.at(i).at(j) = '#';
                }
            }
        }
    }

    vector<vector<ll>> dist(h, vector<ll>(w, numeric_limits<ll>::max()));
    dist.at(0).at(0) = 0;
    REP(i, h){
        REP(j, w){
            if(i > 0){
                if(s.at(i - 1).at(j) == '.' && s.at(i).at(j) == '#'){
                    dist.at(i).at(j) = min(
                        dist.at(i).at(j), dist.at(i - 1).at(j) + 1);
                }else{
                    dist.at(i).at(j) = min(
                        dist.at(i).at(j), dist.at(i - 1).at(j));
                }
            }

            if(j > 0){
                if(s.at(i).at(j - 1) == '.' && s.at(i).at(j) == '#'){
                    dist.at(i).at(j) = min(
                        dist.at(i).at(j), dist.at(i).at(j - 1) + 1);
                }else{
                    dist.at(i).at(j) = min(
                        dist.at(i).at(j), dist.at(i).at(j - 1));
                }
            }
        }
    }
    cout << dist.at(h - 1).at(w - 1) + (end_is_black && start_is_black) << endl;
    return 0;
}
