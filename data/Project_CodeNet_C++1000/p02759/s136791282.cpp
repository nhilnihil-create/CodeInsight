#include <bits/stdc++.h>
using namespace std;

int main(){
    int s;
    cin >> s;
    if (s%2 != 0){
        std::cout << (s+1)/2 << std::endl;
    }
    else {std::cout << s/2 << std::endl;}
    return 0;
}