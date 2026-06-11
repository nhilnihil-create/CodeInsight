#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int N, M;
    int s,c;
    int flg_ne = 0, ans = 0;
    vector<int> the_num{10,10,10};

    std::cin >> N >> M;

    for(int i = 0; i < M; i++){
        std::cin >> s >> c;
        if(the_num[3-N+s-1] == 10){
            the_num[3-N+s-1] = c;
        }else{
            if(the_num[3-N+s-1] != c){
                flg_ne = 1;
                break;
            } 
        }
    }
    if(the_num[3-N]==0){
        if(N != 1){
            flg_ne = 1;
        }
    }
    if(the_num[0] == 10){
        the_num[0] = 1;
    }
    if(the_num[1] == 10){
        if(N == 2){
            the_num[1] = 1;
        }else{
            the_num[1] = 0;
        }
    }
    if(the_num[2] == 10){
        the_num[2] = 0;
    }

    if(flg_ne == 1){
        std::cout << -1;
    }else{
        if(N == 1){
            std::cout << the_num[2];
        }else if(N == 2){
            std::cout << the_num[1] << the_num[2];
        }else if(N == 3){
            std::cout << the_num[0] << the_num[1] << the_num[2];
        }
    }

}