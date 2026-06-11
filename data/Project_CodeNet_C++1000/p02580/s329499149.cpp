#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <numeric>
#include <cmath>
#include <iomanip> //cout << fixed << setprecision(15) << << endl;
#include <cassert>

using namespace std;


#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define P pair<int,int>

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;


int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    int m, h, w;
    cin >> h >> w >> m;
    vector<P> tate(h), yoko(w);
    rep(i,h) tate[i].second = i;
    rep(i,w) yoko[i].second = i;
    set<P> bomb;

    while(m--){
        int hm,wm;
        cin >> hm >> wm;
        hm--; wm--;
        bomb.insert(P(hm,wm));
        tate[hm].first++;
        yoko[wm].first++;
    }
    sort(tate.rbegin(),tate.rend());
    sort(yoko.rbegin(),yoko.rend());
    int tatemax = tate[0].first, yokomax = yoko[0].first;

    bool ok = false;
    rep(i,h){
        rep(j,w){
            if (tate[i].first != tatemax) break;
            if (yoko[j].first != yokomax) break;
            auto itr = bomb.find(P(tate[i].second, yoko[j].second));
            if(itr == bomb.end()){
                //爆弾がなかった
                ok = true;
                break;
            }
        }
        if(ok) break;
    }
    int ans = tate[0].first + yoko[0].first;
    if(!ok) ans--;

    cout << ans << endl;

}

