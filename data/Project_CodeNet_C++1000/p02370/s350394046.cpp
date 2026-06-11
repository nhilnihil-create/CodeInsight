/*トポロジカルソート*/
#include<iostream>
#include<vector>
#include<queue>

using Graph = std::vector<std::vector<size_t>>;

int main(){
    
    size_t v, e;
    std::cin >> v >> e;

    Graph g(v);
    std::vector<size_t> in(v, 0);

    for(size_t i = 0; i < e; i++){
        size_t s, t;
        std::cin >> s >> t;

        g.at(s).emplace_back(t);
        in.at(t)++;
    }

    std::queue<size_t> set;

    for(size_t i = 0; i < in.size(); i++){
        if(in.at(i) == 0) set.emplace(i);
    }

    std::vector<size_t> ans;

    while(!set.empty()){
        auto vertex = set.front(); set.pop();
        ans.emplace_back(vertex);

        for(const auto& e : g.at(vertex)){
            in.at(e)--;
            if(in.at(e) == 0) set.emplace(e);
        }
    }

    for(const auto& e : ans){
        std::cout << e << std::endl;
    }
    
    return 0;
}

/*
for(size_t i = 0; i < v; i++){
    std::cout << "in size: " << in.at(i) << ", out vertex: ";
    for(size_t j = 0; j < g.at(i).size(); j++){
        std::cout << g.at(i).at(j) << ", ";
    }std::cout << std::endl;
}
*/

