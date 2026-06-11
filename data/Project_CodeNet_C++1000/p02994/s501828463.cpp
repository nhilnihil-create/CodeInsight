#include<iostream>
using namespace std;

int main(){
    int N, L, ans;
    std::cin >> N >> L;

    ans = (L - 1) * N + (N + 1)*N/2;

    if(L >= 0){
        ans = ans - L;
    }else if(L + N - 1 < 0){
        ans = ans - (L + N -1);
    }

    std::cout << ans;
}