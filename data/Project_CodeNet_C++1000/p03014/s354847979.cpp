#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<int>> mat(h);
    rep(i,h){
        string s;
        cin >> s;
        rep(j,s.size()){
            if(s.at(j) == '.') mat.at(i).push_back(1);
            else mat.at(i).push_back(0);
        }
    }

    vector<vector<int>> hs(h),vd(h);
    rep(i,h){
        vector<int> v1(w), v2(w);
        hs.at(i) = v1;
        vd.at(i) = v2;
    }

    rep(i,h){
        int j = 0;
        int st_idx = 0;
        int lcnt = 0;
        while(j<w){
            if(mat.at(i).at(j) == 0){
                for(int k =st_idx;k<j;k++){
                    hs.at(i).at(k) = lcnt;
                }
                lcnt = 0;
                st_idx = j+1;
            }
            else {
                lcnt++;
            }
            j++;
        }
        for(int k =st_idx;k<j;k++){
            hs.at(i).at(k) = lcnt;
        }
    }
    rep(i,w){
        int j = 0;
        int st_idx = 0;
        int lcnt = 0;
        while(j<h){
            if(mat.at(j).at(i) == 0){
                for(int k =st_idx;k<j;k++){
                    vd.at(k).at(i) = lcnt;
                }
                lcnt = 0;
                st_idx = j+1;
            }
            else {
                lcnt++;
            }
            j++;
        }
        for(int k =st_idx;k<j;k++){
            vd.at(k).at(i) = lcnt;
        }
    }
    // rep(i,h){
    //     rep(j,w){
    //         cout << hs.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // rep(i,h){
    //     rep(j,w){
    //         cout << vd.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }

    int res = 0;
    rep(i,h){
        rep(j,w){
            res = max(res, vd.at(i).at(j) + hs.at(i).at(j) - 1);
        }
    }
    cout << res << endl;
    return 0;
}