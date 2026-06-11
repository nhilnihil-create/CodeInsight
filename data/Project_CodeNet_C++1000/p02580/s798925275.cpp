#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W, M;
    cin >> H >> W >> M;

    vector<int> h_num(H);
    vector<int> w_num(W);
    int max_h = 0;
    int max_w = 0;

    set<pair<int, int>> s;

    for(int i=0; i<M; ++i){
        int h, w;
        cin >> h >> w;
        h--; w--;
        h_num[h]++;
        max_h = max(max_h, h_num[h]);
        w_num[w]++;
        s.emplace(h, w);
        max_w = max(max_w, w_num[w]);
    }

    //candidate h, w, indexs
    vector<int> candidate_h_idx;
    for(int h=0; h<H; ++h){
        if(h_num[h] != max_h) continue;
        candidate_h_idx.push_back(h);
    }


    vector<int> candidate_w_idx;
    for(int w=0; w<W; ++w){
        if(w_num[w] != max_w) continue;
        candidate_w_idx.push_back(w);
    }

    //tmp ans
    int ans = max_h + max_w;

    //check if all the points are crossed or not
    bool all_crossed = true;

    for(int h : candidate_h_idx){
        for(int w : candidate_w_idx){
            if(s.count({h, w})) continue;
            all_crossed = false;
            break;
        }
    }

    if(all_crossed){
        cout << ans -1 << endl;
    }else{
        cout << ans << endl;
    }

}
