
#include<iostream>
using namespace std;

string inp;
char buff[6];

int main(){
    std::cin >> inp;
    inp.copy(buff, 6);
    
    if(buff[2]==buff[3]&&buff[4]==buff[5]){
        std::cout << "Yes";
    }else{
        std::cout << "No";
    }
}