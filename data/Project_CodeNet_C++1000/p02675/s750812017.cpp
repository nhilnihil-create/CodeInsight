#include<iostream>
#include<vector>

int main(void){
    int n;
    std::cin >> n;
    std::vector<int> a = {1, 1, 0, 2, 0, 0, 1, 0, 1, 0};
    std::string b;
    int one = n % 10;

    
    if(a[one] == 0) b = "hon";
    else if(a[one] == 1) b = "pon";
    else b = "bon";
    std::cout << b << std::endl;

    // for(int i = 0; i < n; i++){
    //     if(a[i] == 0) b = "hon";
    //     else if(a[i] == 1) b = "pon";
    //     else b = "bon";
    //     std::cout << i << b << std::endl;
    // }
    return 0;
}
