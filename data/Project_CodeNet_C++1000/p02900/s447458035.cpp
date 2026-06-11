#include<iostream>
#include<vector>
#include<cmath>
#include<set>

std::set<int> primeFactorization(long long n){
    std::set<int> s;
    int nm = std::sqrt(n);
    for(int i = 2; i <= nm; i++){
        if(n % i == 0){
            s.insert(i);
            do{
                n /= i;
            }while(n % i == 0);
        }
    }
    if(n != 1) s.insert(n);
    return s;
}

int main(void){
    long long a, b;
    std::cin >> a >> b;
    std::set <int> sa, sb;
    sa = primeFactorization(a);
    sb = primeFactorization(b);
    int ans = 0;
    for(auto i = sa.begin(); i != sa.end(); i++){
        if(sb.find(*i) != sb.end()) ans++;
    }
    ans++;
    std::cout << ans << std::endl;
    return 0;
}