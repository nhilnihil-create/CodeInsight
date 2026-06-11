#include<iostream>
#include<string>

int main(){
        int N;
        std::cin >> N;
        std::string ABC;
        ABC.resize(N);
        for (int i = 0; i < N; i++){
        std::cin >> ABC[i];
    }
        int abcs = 0;
        for (int i = 0; i < N-2; i++){
        if (ABC.substr(i,3) == "ABC") abcs++;
    }
        std::cout << abcs << std::endl;
}