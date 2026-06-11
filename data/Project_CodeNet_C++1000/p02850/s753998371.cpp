#include <iostream>
#include <vector>

int edge_color[100010];
std::vector<std::pair<int, int>> edges[100010]; // {to, num}

void dfs(int i, int used_color){
    int color = 0;
    for(auto edge : edges[i]){
        if(edge_color[edge.second]) continue;
        color++;
        if(color == used_color) color++;
        edge_color[edge.second] = color;
        dfs(edge.first, color);
    }
}





int main(){
    int n;
    std::cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b;
        std::cin >> a >> b;
        a--; b--;
//        edges[i] = Edge(a, b)
        edges[a].push_back({b, i});
        edges[b].push_back({a, i});
    }
    int max = 0;
    for(auto edge : edges){
        max = std::max(max, (int)edge.size());
    }
    dfs(0, 0);
    std::cout << max << std::endl;
    for(int i = 0; i < n-1; i++){
        std::cout << edge_color[i] << std::endl;
    }
    return 0;
}
