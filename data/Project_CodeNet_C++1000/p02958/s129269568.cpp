#include<iostream>
#include<vector>

int main(void){
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for(int i = 0; i < n; i++){
        std::cin >> p[i];
    }
    bool flag, flag2;
    flag = 0;
    flag2 = 0;
    for(int k = 0; k < n-1; k++){
        if(p[k] > p[k+1]){
            flag = 1;
            break;
        }
    }
    if(!flag){
        std::cout << "YES" << std::endl;
        flag2 = 1;
    }
    if(!flag2){
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                flag = 0;
                std::swap(p[i], p[j]);
                for(int k = 0; k < n-1; k++){
                if(p[k] > p[k+1]){
                    std::swap(p[i], p[j]);
                    flag = 1;
                    break;
                }
                }
                if(!flag){
                std::cout << "YES" << std::endl;
                flag2 = 1;
                }
            }
        }
    }

    if(!flag2){
        std::cout << "NO" << std::endl;
    }
    return 0;
}