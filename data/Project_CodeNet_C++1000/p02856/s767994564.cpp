#include<iostream>

using ll = long long;

int main(){
    int m;
    std::cin >> m;
    ll digit=0,total=0;
    for(int i=0 ; i<m ;i++){
        ll d,c;
        std::cin >> d >> c;
        digit += c;
        total += d*c;
    }
    ll moveup = (total-1)/9;
    std::cout << digit+moveup-1 << "\n";
}
