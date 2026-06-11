#include <bits/stdc++.h>
int main(){
    int64_t x, k;
    std::cin >> x >> k;
    if(x>k) x = x-x/k*k;
    if(k-x<x) x = k-x;
    std::cout << x << '\n';
}