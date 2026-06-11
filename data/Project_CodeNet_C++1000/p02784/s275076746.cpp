#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int H,N;
    int A;
    int ans = 0;

    std::cin >> H >> N;
    for(int i = 0; i < N; i++){
        scanf("%d", &A);
        ans = ans + A;
    }

    if(ans >= H){
        std::cout << "Yes";
    }else{
        std::cout << "No";
    }
}