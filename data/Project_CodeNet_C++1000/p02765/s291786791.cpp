#include<iostream>
#include<string>

int main(){
        int N,R;
        std::cin >> N;
        std::cin >> R;
        if(N >= 10)
                std::cout << R;
        else
                std::cout << R + 100 * (10 - N);
}