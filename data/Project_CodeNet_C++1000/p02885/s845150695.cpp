#include<iostream>

int main() {
        int A,B;
        std::cin >> A >> B;
        if(B*2 >= A) std::cout<<0;
        else std::cout<<A-B*2;
}