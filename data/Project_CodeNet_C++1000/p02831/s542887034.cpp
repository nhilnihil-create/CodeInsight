#include<iostream>
#include<vector>
#include<string>

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

// おまけ
long long lcm(long long a, long long b){
    return a * (b / gcd(a, b));
}

int main(){
    long long a, b;
    std::cin >> a >> b;
    std::cout << lcm(a, b) << std::endl;
    return 0;
}
