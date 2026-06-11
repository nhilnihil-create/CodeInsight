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
    vector<int> state(V, 0);

    for (int i = 0; i < E; i++) {
        state[edge[i].second]++;
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            if (state[i] == 0) {
                ans.push_back(i);
                for (int j = 0; j < edge.size(); j++) {
                    if (edge[j].first == i) {
                        state[edge[j].second]--;
                        edge[j] = edge.back();
                        edge.pop_back();
                        j--;
                    }
                }
                state[i]--;
                break;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}

