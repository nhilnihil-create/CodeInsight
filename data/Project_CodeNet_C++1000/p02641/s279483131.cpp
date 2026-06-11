#include<iostream>
#include<map>
using namespace std;

int main(){
    int X, N, p;
    int flg_found_p = 0, flg_found_m = 0;
    int tmp_p, tmp_m;
    int ans_p = 1000, ans_m = 1000;
    map<int, int> f_list;

    std::cin >> X >> N;

    for(int i = 0; i < N; i++){
        std::cin >> p;
        f_list[p] = 1;
    }

    for(int i = 0; i <= 100; i++){
        //X+i
        tmp_p = X + i;
        tmp_m = X - i;
        if(!f_list.count(tmp_p)){
            flg_found_p = 1;
            ans_p = tmp_p;    
        }
        if(!f_list.count(tmp_m)){
            flg_found_m = 1;
            ans_m = tmp_m;
        }
        if(flg_found_m == 1 || flg_found_p == 1){
            break;
        }
    }

    if(ans_p < ans_m){
        std::cout << ans_p;
    }else{
        std::cout << ans_m;
    }

}