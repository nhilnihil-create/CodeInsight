#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

int main(){
    int N, tmp;
    map<int, int> dic;
    bool flg_dist = 1;

    std::cin >> N;

    for(int i = 0; i < N; i++){
        scanf("%d", &tmp);
    //    std::cout << tmp;
        if(dic.count(tmp)){
            flg_dist = 0;
            break;
        }else{
            dic[tmp] = 0;
        }
    }
    if(flg_dist == 1){
        std::cout << "YES";
    }else{
        std::cout << "NO";
    }
}