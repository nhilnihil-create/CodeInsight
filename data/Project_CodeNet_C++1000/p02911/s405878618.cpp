#include<iostream>
#include<vector>

int main(void){
    int n, k, q;
    std::cin >> n >> k >>q;
    std::vector<int> at(n);
    for(int i = 0; i < q; i++){
        int a;
        std::cin >> a;
        a--;
        at[a]++;
    }
    for(int i = 0; i < n; i++){
        if(k - q + at[i] > 0) std::cout << "Yes" << std::endl;
        else std::cout << "No" << std::endl;
    }
    return 0;
}