#include<iostream>
#include<vector>
#include<string>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> h(n);
    for(int i = 0; i < n; i++){
        std::cin >> h[i];
    }

    // 右から見ていく
    for(int i = n - 1; i >= 1; i--){
        if(h[i - 1] > h[i]){
            h[i - 1]--;
            if(h[i - 1] > h[i]){
                std::cout << "No" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "Yes" << std::endl;
    return 0;
}
