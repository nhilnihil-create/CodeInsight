#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    // Your code here!
    int A, B, C;
    std::cin >> A >> B >> C;
    std::cout << std::max(C - (A - B), 0) << std::endl;
}
