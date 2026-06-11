#include<iostream>
#include<set>
#include<vector>

const int MOD = 1e9 + 7;

int main(void){
    int n, m;
    std::cin >> n >> m;
    std::vector<int> b(n+1);
    std::set<int> a;
    for(int i = 0; i < m; i++){
        int tmp;
        std::cin >> tmp;
        a.insert(tmp);
    }
    b[0] = 1;
    if(a.find(1) != a.end()) b[1] = 0;
    else b[1] = 1;
    for(int i = 2; i <= n; i++){
        if(a.find(i) != a.end()) b[i] = 0;
        else b[i] = (b[i-1] + b[i-2]) % MOD;
    }
    std::cout << b[n] << std::endl;
    return 0;
}