#include<iostream>
#include<vector>

int main(void){
    int n, x;
    std::cin >> n >> x;
    std::vector<int> l(n);
    for(int i = 0; i < n; i++){
        std::cin >> l[i];
    }
    int d = 0;
    int cnt = 1;
    for(int i = 0; i < n; i++){
        d = d + l[i];
        if(d > x){
            break;
        }
        cnt++;
    }
    std::cout << cnt << std::endl;
    return 0;
}