#include<iostream>
#include<algorithm>
#include<vector>

int main(void){
    int n;
    std::cin >> n;
    std::vector<int> a(n), oa(n);
    int tmp;
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    oa = a;
    std::sort(a.begin(), a.end());
    int max2 = a[n-2];
    int max = a[n-1];
    for(int i = 0; i < n; i++){
        if(oa[i] == max){
            std::cout << max2 << std::endl;
        }else{
            std::cout << max << std::endl;
        }
    }
    return 0;
}