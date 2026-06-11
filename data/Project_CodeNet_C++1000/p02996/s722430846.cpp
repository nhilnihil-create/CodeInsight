#include <bits/stdc++.h>

int main(){
    int N;
    std::cin >> N;
    std::vector< std::pair< int , int > > AB(N);
    for(int i=0; i<N; i++){
        std::cin >> AB[i].second >> AB[i].first;
    }
    
    std::sort(AB.begin(), AB.end());
    int time = 0;
    for(int i=0; i<N; i++){
        time += AB[i].second;
        if(time > AB[i].first){
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    
    std::cout << "Yes" << std::endl;
    
    return 0;
}

