#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

int main(){
    int N;
    string S;
    std::map<std::string, int> dic;
    int max = 0;
    string tmp;
    int tmp_i;

    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> S;

        if(dic.count(S)){
            dic[S] = dic[S] + 1;
        }else{
            dic[S] = 1;
        }
        if(dic[S] > max){
            max = dic[S];
        }
    }

    //std::cout << "------------------" << "\n";

    auto iter = dic.begin();
    N = dic.size();
    for(int i = 0; i < N; i++){
        tmp_i = iter->second;
        if(tmp_i == max){
            std::cout << iter->first << "\n";
        }
        iter = std::next(iter,1);
    }


}
