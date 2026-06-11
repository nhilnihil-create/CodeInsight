#include<iostream>
using namespace std;

int mypow(int x, int y);

int main(){
    int a, b;
    int ans_a = 0, ans_b = 0;

    std::cin >> a >> b;

    for(int i = 0; i < b; i++){
        ans_a = a * mypow(10,i) + ans_a;
    }

    for(int i = 0; i < a; i++){
        ans_b = b * mypow(10,i) + ans_b;
    }

    //std::cout << ans_a << "\n";
    //std::cout << ans_b << "\n";

    if(a < b){
        std::cout << ans_a;
    }else{
        std::cout << ans_b;
    }

}

int mypow(int x, int y){
    int ans = 1;
    for(int i = 0; i < y; i++){
        ans = ans * x;
    }
    return ans;
}