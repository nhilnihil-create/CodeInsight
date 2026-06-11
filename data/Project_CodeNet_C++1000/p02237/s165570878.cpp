#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main(){
    int n;
    std::cin >> n;
    int list[n][n] = {};
    std::vector<std::vector<int>> vertex;
    int tmp2;
    int num;
    for(int i=0;i<n;i++){
        std::vector<int> tmp;
        std::cin >> tmp2;
        std::cin >> num;
        for(int j=0;j<num;j++){
            std::cin >> tmp2;
            tmp.push_back(tmp2);
        }
        vertex.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<vertex[i].size();j++){
            if(vertex[i][j] > 0){
                list[i][vertex[i][j]-1] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cout << list[i][j];
            if(j!=n-1){
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}

