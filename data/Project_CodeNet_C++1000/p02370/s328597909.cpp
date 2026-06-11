#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
using namespace std;

vector <int> edges[10000];
int incoming[10000];
bool used[10000];
vector <int> order;

void dfs(int cur){
    used[cur] = true;
    for(int i = 0; i < edges[cur].size(); i++){
        if(!used[edges[cur][i]]){
            dfs(edges[cur][i]);
        }
    }
    order.push_back(cur);
    return;
}

int main(){
    int N;
    int M;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int s;
        int t;
        cin >> s >> t;
        edges[s].push_back(t);
        incoming[t] ++;
    }
    vector <int> sources;
    for(int i = 0; i < N; i++){
        if(incoming[i] == 0){
            sources.push_back(i);
        }
    }
    for(int i = 0; i < sources.size(); i++){
        dfs(sources[i]);
    }

    for(int i = 0; i < N; i++){
        cout << order[N - 1 - i] << endl;
    }
    return 0;
}

