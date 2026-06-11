
#include <iostream>

int main(){

    int A,B;

    std::cin >> A  >> B ;

    int X_min, X_max;
    int Y_min, Y_max;
    int ans = -1; // 初期値でfalseを与える
    // 8%消費税でA円のお釣りを与える代金X
    // A / 0.08 =< X < (A+1)/0.08

    // A * 100 / 8 が余り0の時 A mod 2 = 0
    X_min = (A % 2 == 0) ? A * 100 / 8 : A * 100 / 8 + 1;
    X_max = ((A+1) % 2 == 0 ) ? (A+1) * 100 / 8 -1  : (A+1) * 100 / 8;

    Y_min = B * 10;
    Y_max = (B+1) * 10  - 1;
    bool flag_findone = false;


    int tmp = 0;
    for(int i = 0; i < X_max - X_min; ++i){
        tmp = i + X_min;

        for(int j = 0; j < Y_max - Y_min; ++j){

            if(tmp == j + Y_min && flag_findone == false){
                ans = tmp;
                flag_findone = true;
            }
        }
    }
    

    std::cout << ans << std::endl;
}