#include <bits/stdc++.h>
using namespace std;

int main(){
    long long  n, a, b;
    cin >> n >> a >> b;/*
    if(a == 0){cout << 0 << endl;return 0;}
    else if(b == 0){std::cout << n << std::endl; return 0;}
    */
    long long sum = n/(a+b) * a;
    long long par = n%(a+b);
    sum += min<long>(par, a);
    std::cout << sum  << std::endl;
    return 0;
}