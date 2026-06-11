#include <iostream>
#include <vector>
using namespace std;
int h,w,k;

int sum_matrix(const vector<vector<int>>& vv){
    int count=0;
    for(const auto& v : vv){
        for(const auto& e : v){
            count += e;
        }
    }
    return count;
}

int main(){
    cin >> h >> w >> k;
    vector<vector<int>> data(6, vector<int>(6,0));
    // read data
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            char c; cin >> c;
            if(c=='#') data[i][j] = 1;
        }
    }
    // make index
    // for h
    vector<vector<int>> lst_h(1<<h);
    for (int bit = 0; bit < (1<<h); ++bit) {
        for (int i = 0; i < h; ++i) {
            if (bit & (1<<i)) {
                lst_h[bit].push_back(i);
            }
        }
    }
    // for w
    vector<vector<int>> lst_w(1<<w);
    for (int bit = 0; bit < (1<<w); ++bit) {
        for (int i = 0; i < w; ++i) {
            if (bit & (1<<i)) {
                lst_w[bit].push_back(i);
            }
        }
    }
    // check
    int ans=0;
    for(int bit_h = 0; bit_h < (1<<h); ++bit_h) {
        for(int bit_w = 0; bit_w < (1<<w); ++bit_w){
            vector<vector<int>> dmy=data;
            for(auto i : lst_h[bit_h]) for(int j=0; j<6; j++) dmy[i][j]=0;
            for(int i=0; i<6; i++) for(auto j : lst_w[bit_w]) dmy[i][j]=0;
            if(sum_matrix(dmy)==k) ans++;
        }
    }
   cout << ans << "\n";
}