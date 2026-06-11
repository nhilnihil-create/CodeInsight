#include <iostream>
using namespace std;
int main(void){
    int a;
    string s;
    std::cin >> a >> s;
    std::cout << ((a >= 3200) ? s : "red") << std::endl;
}
