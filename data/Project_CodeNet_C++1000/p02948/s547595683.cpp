#include <bits/stdc++.h>

int main(){
    int N, M;
    std::cin >> N >> M;
    std::vector< std::pair< int, int > > AB(N+1);
    for(int i=0; i<N; i++){
        std::cin >> AB[i].first >> AB[i].second;
    }
    AB[N].first = 1e9;
    AB[N].second = 0;
    std::sort(AB.begin(), AB.end());
    
    std::priority_queue<int> que;
    
    int index = 0;
    int ans = 0;
    for(int i=1; i<=M; i++){
        while(AB[index].first == i){
            que.push(AB[index].second);
            index++;
        }
        if(!que.empty()){
            ans += que.top();
            que.pop();
        }
    }
    
    std::cout << ans << std::endl;
    
    return 0;
}

