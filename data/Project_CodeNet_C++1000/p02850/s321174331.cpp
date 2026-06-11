#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N-1), b(N-1);
    for ( int i = 0; i < N-1; ++i){
        cin >> a.at(i) >> b.at(i);
    }
    
    vector<vector<int>> G(N); //隣接リストによるグラフの表現
    vector<pair<int,int>> E_in; //辺の入力の順番を保持
    for ( int i = 0; i < N-1; ++i){
        int x = a.at(i);
        int y = b.at(i);
        --x; --y;
        G.at(x).push_back(y);
        G.at(y).push_back(x);
        pair<int,int> p = make_pair(x,y);
        E_in.push_back(p);
    }
    
    
    
    queue<int> que;
    vector<int> used(N,0);
    vector<int> parent(N,0); //親との間いある辺の色
    int max_color = 0;
    map<pair<int,int>,int> E_num; //辺に割り振った色
    que.push(0);
    used[0] = 1;
    while ( que.size() != 0 ){
        int state = que.front(); que.pop();
        int color_num = 0;
        for ( auto next: G[state] ){
            if ( used[next] != 1 ){
                ++color_num;
                used[next] = 1;
                if ( color_num == parent[state] ){
                    ++color_num;
                }
                pair<int,int> p = make_pair(state,next);
                E_num[p] = color_num;
                parent[next] = color_num;
                que.push(next);
            }
        }
        max_color = max(max_color,color_num);
    }
    
    cout << max_color << endl;
    for ( auto i : E_in ){
        cout << E_num[i] << endl;
    }
    
    
    
    return 0;
}
