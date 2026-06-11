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

    int maxStep = 0;
    int step = 0;
    for(int i = 1; i < n; i++){
        if(h[i - 1] >= h[i]){
            step++;
            maxStep = std::max(maxStep, step);
        }else{
            step = 0;
        }
    }

    std::cout << maxStep << std::endl;
    return 0;
}
