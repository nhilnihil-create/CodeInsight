#include<iostream>
#define ll long long

int main(){
ll r,c;
std::cin >> r >> c;
(r==1 || c==1)?std::cout << "1" : std::cout << (r*c+2-1)/2;
 return 0;
}
