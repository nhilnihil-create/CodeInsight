#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <list>

static const int MAX = 100000;

std::vector<int> Graph[MAX];
//std::list<int> out;
std::stack<int> outs;
bool isVisited[MAX];
int N;

void dfs(int u) {
    isVisited[u] = true;
    for (int i = 0; i < Graph[u].size(); i++) {
        int v = Graph[u][i];
        //ha az adott vertex meg nem vizsgalt
        if (!isVisited[v]) {
            //std::cout << "run: " << v << std::endl;
            dfs(v);
        }
    }
    //out.push_front(u);
    outs.push(u);
}

int main()
{
    int start, target, M;
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) isVisited[i] = false;
    for (int i = 0; i < M; i++) {
        std::cin >> start >> target;
        Graph[start].push_back(target);
    }

    for (int i = 0; i < N; i++) {
        if (!isVisited[i])
            dfs(i);
    }

    /*for (std::list<int>::iterator it = out.begin(); it != out.end(); it++) {
        std::cout << *it << std::endl;
    } */
    while (!outs.empty()) {
        std::cout << outs.top() << std::endl;
        outs.pop();
    }


    return 0;
}

