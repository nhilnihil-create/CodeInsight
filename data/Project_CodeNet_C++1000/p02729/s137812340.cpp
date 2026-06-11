
#include<iostream>
using namespace std;

int N,M;
int ans;
long nCr(int n, int r);


int main(){
    std::cin >> N >> M;
    ans = nCr(N+M,2) - N*M;
    std::cout << ans;
}

long nCr(int n, int r) {
    long ans = 1;
    for (int i = n; i > n - r; --i) {
        ans = ans*i;
    }
    for (int i = 1 ; i < r + 1; ++i) {
        ans = ans / i;
    }
    return ans;
}