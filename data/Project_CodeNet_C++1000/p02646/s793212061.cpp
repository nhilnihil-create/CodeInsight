#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
using ll = long long;

int main(){
    ll A, B, V, W, T; std::cin >> A >> V >> B >> W >> T;

    ll dx=abs(A-B), dv=(V-W)*T;
    if(dx<=dv){
        std::cout << "YES";
    }else{
        std::cout << "NO";
    }
    return 0;
}
