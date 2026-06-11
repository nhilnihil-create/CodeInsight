#include <iostream>
#include <vector>

using namespace std;

void fill(vector<vector<int>>& res, const vector<int>& S, int level){
    if(S.size() <= 1) return;
    vector<vector<int>> v(2);
    for(int i=0;i<S.size();i++){
        v[i%2].push_back(S[i]);
    }
    for(auto& a : v[0]){
        for(auto& b : v[1]){
            res[a][b] = res[b][a] = level;
        }
    }
    for(auto s : v) fill(res, s, level+1);
}

vector<vector<int>> solve(int N){
    vector<int> S(N);
    for(int i=0;i<N;i++) S[i] = i;
    vector<vector<int>> res(N, vector<int>(N, 0));
    fill(res, S, 1);
    return res;
}

int main(){
    int N;
    while(cin >> N){
        auto res = solve(N);
        for(int i=0;i<N-1;i++){
            for(int j=i+1;j<N-1;j++){
                cout << res[i][j] << " ";
            }
            cout << res[i].back() << endl;
        }
    }
}