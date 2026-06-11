#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> d(n);
    for(int i = 0; i < n; i++){
        std::cin >> d[i];
    }
    std::sort(d.begin(), d.end());

    int ind = n / 2 - 1;
    std::cout <<  std::max(d[ind + 1] - (d[ind] + 1) + 1, 0) << std::endl;
    return 0;
}
