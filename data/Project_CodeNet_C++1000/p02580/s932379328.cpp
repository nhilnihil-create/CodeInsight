#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
const long long INF = 1LL << 60;
const int MOD = 1e9 + 7;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


/* ACL */

//using namespace atcoder;



int main(){
    int H,W,M;
    cin >> H >> W >> M;
    //vector<vector<bool>> table(H+1,vector<bool>(W+1,false));
    //map<pair<int,int>,bool> table;
    set<pair<int,int>> table;


    //the number of bombs by h,w
    vector<int> h_cnt(H+1,0);
    vector<int> w_cnt(W+1,0);

    //max bombs in arrow    
    int h_max = 0;
    int w_max = 0;

    rep(i,M){
        int h,w;
        cin >> h >> w;
        //table[{h,w}] = true;
        table.insert({h,w});
        h_cnt.at(h) += 1;
        w_cnt.at(w) += 1;

        chmax(h_max,h_cnt.at(h));
        chmax(w_max,w_cnt.at(w));
    }

    //kiyasume
    if(H == 1 || W == 1){
        cout << M << endl;
        return 0;
    }

    //which column or row has max bombs?
    vector<int> maxHs(0);
    vector<int> maxWs(0);

    rep(i,H+1){
        if(h_cnt.at(i) == h_max){
            maxHs.push_back(i);
        }
    }
    rep(i,W+1){
        if(w_cnt.at(i) == w_max){
            maxWs.push_back(i);
        }
    }

    //is there a bomb at hypocenter?
    int ans = h_max + w_max - 1;
    rep(i,maxHs.size()){
        rep(j,maxWs.size()){
            if(table.find({maxHs[i],maxWs[j]}) == table.end()){
                ans += 1;
                cout << ans << endl;
                return 0;
            }
        }
    }

    cout << ans << endl;
    return 0;
    
}