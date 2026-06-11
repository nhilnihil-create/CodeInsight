#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int N;
    std::cin >> N;
    std::vector<int> v(N);
    
    for (int i = 0; i < N; i++) {
        std::cin >> v[i];
    }
    
    int swap = 0;
    for (int i = 0; i < N; i++) {
       if (v[i] == i + 1) {
           continue;
       }
       if (v[v[i] - 1] == i + 1) {
           swap = swap + 1;
           continue;
       } else {
           swap = 100;
       }
    }
    
    if (swap <= 2) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}
