#include<iostream>
#include<vector>
#include<algorithm>

int main(void){
    int n;
    std::cin >> n;
    std::vector<int> d(n);
    for(int i = 0; i < n; i++){
        std::cin >> d[i];
    }
    std::sort(d.begin(), d.end());
    std::cout << d[n/2] - d[n/2-1] << std::endl;
    return 0;
}