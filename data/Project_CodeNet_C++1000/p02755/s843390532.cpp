#include<iostream>
#include<vector>
#include<string>
#include<list>

// O(1) answer

int main(){
    int a, b;
    std::cin >> a >> b;
    double a_start = a / 0.08;
    double a_end = (a + 1) / 0.08;
    double b_start = b / 0.10;
    double b_end = (b + 1) / 0.10;

    std::list<int> x_a, x_b;
    for(int x = a_start; x <= a_end; x++){
        if(x * 8 / 100 == a) x_a.push_back(x);
    }
    for(int x = b_start; x <= b_end; x++){
        if(x * 10 / 100 == b) x_b.push_back(x);
    }

    for(auto aa : x_a){
        for(auto bb : x_b){
            if(aa == bb){
                std::cout << aa << std::endl;
                return 0;
            }
        }
    }

    std::cout << -1 << std::endl;
    return 0;
}
