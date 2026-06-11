#include<iostream>
#include<vector>

int main(void){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    int x = 0;
    for(int i = 0; i < n; i++){
        int ae = a[i];
        if(i % 2 != 0){
            ae = -ae;
        }
        x += ae;
    }
    std::cout << x << " ";
    for(int i = 0; i < n-1; i++){
        x = -x + 2 * a[i];
        std::cout << x << " ";
    }
    return 0;
}
