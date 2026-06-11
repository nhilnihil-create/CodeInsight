#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, r;
    cin >> n >> r;
    if (n >10){
        std::cout << r << std::endl;
    }
    else {std::cout << r+100*(10-n) << std::endl;}
    return 0;
}