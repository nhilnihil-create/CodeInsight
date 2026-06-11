#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int main(){
    int V, E;
    cin >> V >> E;
    vector<pair<int, int> > edge(E);
    for (int i = 0; i < E; i++) {
        cin >> edge[i].first >> edge[i].second;
    }
    vector<int> ans;
    vector<int> state(V, 1);
//0: edge[i].secondに載っているため設定できない
//1: 設定できる状態
//2: すでに設定済みなので除外

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            if (state[i] != 2) state[i] = 1;
        }
        for (int i = 0; i < edge.size(); i++) {
            state[edge[i].second] = 0;
        }
        for (int i = 0; i < V; i++) {
            if (state[i] == 1) {
                ans.push_back(i);
                state[i] = 2;
                for (int j = 0; j < edge.size(); j++) {
                    if (edge[j].first == i) {
                        edge.erase(edge.begin() + j);
                        j--;
                    }
                }
                break;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}

