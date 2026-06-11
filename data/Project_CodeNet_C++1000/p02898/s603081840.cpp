#include<iostream>
using namespace std;

int main(){
    int N, K, h;
    int ans = 0;
    std::cin >> N >> K;

    for(int i = 0; i < N; i++){
        std::cin >> h;
        if(h >= K){
            ans++;
        }
    }

    std::cout << ans;

}