#include <iostream>
#include <vector>
using namespace std;

const long long int MOD = 1e9 + 7;

long long int dfs(const int &K, const vector<vector<int>> &graph, const int &now, const int &from){

    int can_use_color_num;
    if(from == -1){
        can_use_color_num = K - 1;
    }else{
        can_use_color_num = K - 2;
    }

    if(K < graph[now].size()){
        return 0;
    }else{
        long long int case_num = 1;
        //現在地から子の方向に繋がっているnodeの数を積の形で数えてる
        for(auto e: graph[now]){
            if(e == from) continue;

            case_num *= can_use_color_num;
            can_use_color_num--;
            case_num %= MOD;
        }
        //dfsでさらに深く潜る
        for(auto e: graph[now]){
            if(e == from) continue;
            case_num *= dfs(K, graph, e, now);
            case_num %= MOD;
        }
        return case_num;
    }
}

int main(){
    int N, K; cin >> N >> K;

    vector<vector<int>> graph(N);
    for(int i = 0; i < N - 1; i++){
        int a, b; cin >> a >> b;a--, b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    long long int answer = K * dfs(K, graph, 0, -1);
    answer %= MOD;
    cout << answer << endl;
    return 0;
}
