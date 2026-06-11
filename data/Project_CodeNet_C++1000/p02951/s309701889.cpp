#include<iostream>
int main() {
        int A,B,C;
        std::cin >> A >> B >> C;
  		if(C-(A-B) < 0) std::cout<<0;
        else std::cout<<C-(A-B);
}