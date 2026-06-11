#include <iostream>
using namespace std;
int main(void){
    int a,b;
    string str;
    std::cin >> a>>b;
    if(a==b)
    str="a == b";
    else if(a<b)
    str="a < b";
    else if(a>b)
    str="a > b";
    std::cout << str << std::endl;
}
