#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n), orderd(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        orderd[i] = a[i];
    }

    std::sort(orderd.begin(), orderd.end());

    if(orderd[n - 1] == orderd[n - 2]){
        // 最大値が2つあればどれ抜いても最大値
        for(int i = 0; i < n; i++){
            std::cout << orderd[n - 1] << std::endl;
        }
    }else{
        // 最大値が1つであればその最大値の場合を除いて全部最大値
        for(int i = 0; i < n; i++){
            if(a[i] == orderd[n - 1]){
                std::cout << orderd[n - 2] << std::endl;
            }else{
                std::cout << orderd[n - 1] << std::endl;
            }
        }
    }

    return 0;
}
