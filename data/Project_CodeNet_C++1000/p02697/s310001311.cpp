typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n,m;
    std::cin >> n>>m;
    if(m%2==0){
        for (int i = 0; i < m/2; i++) {
            std::cout << i+1<<" "<<m-i << std::endl;
        }
        for (int i = 0; i < m/2; i++) {
            std::cout << m+i+1<<" "<<m+m+1-i << std::endl;
        }
    }else{
        for (int i = 0; i < m/2; i++) {
            std::cout << i+1<<" "<<m-i << std::endl;
        }
        for (int i = 0; i < m/2+1; i++) {
            std::cout << m+i+1<<" "<<m+m+1-i << std::endl;
        }
    }
}
