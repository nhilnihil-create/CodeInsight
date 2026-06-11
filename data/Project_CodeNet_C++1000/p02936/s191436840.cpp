#include<iostream>
#include<vector>
#include<queue>

struct Node{
    int value = 0;
};

int main(void){
    int n, q;
    std::cin >> n >> q;
    std::vector<Node> node(n);
    std::vector<int> used(n);
    std::vector<std::vector<int>>edge(n);
    int a, b;
    for(int i = 0; i < n-1; i++){
        std::cin >> a >> b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    int p, x;
    for(int i = 0; i < q; i++){
        std::cin >> p >> x;
        p--;
        node[p].value += x;
    }

    std::queue<int> que;
    que.push(0);
    used[0] = 1;
    while(!que.empty()){
        int cur = que.front(); que.pop();
        int size = edge[cur].size();
        used[cur] = 1;
        for(int i = 0; i < size; i++){
            int next = edge[cur][i];
            if(used[next]) continue;
            node[next].value += node[cur].value;
            que.push(next);
        }
    }

    for(int i = 0; i < n; i++){
        std::cout << node[i].value << " ";
    }
    std::cout << std::endl;

    return 0;
}