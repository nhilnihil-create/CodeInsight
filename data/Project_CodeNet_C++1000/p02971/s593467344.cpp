#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
#include <set>
#include <map>
#include <unordered_map>
#include <cassert>
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    fast_io();

    int n,first=0,second=0; std::cin >> n;
    std::vector<int> a(n,0);
    rep(i,n){
        std::cin >> a[i];
        if(first<a[i]){
            first = a[i];
        }else if(second<a[i]){
            second = a[i];
        }
    }

    rep(i,n){
        if(a[i]==first) std::cout << second << "\n";
        else std::cout << first << "\n";
    }
    return 0;
}
