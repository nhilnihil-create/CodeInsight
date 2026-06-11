#include<iostream>
#include<vector>
using namespace std;

int main(){
    string S;
    int N;
    int buff;

    std::cin >> N >> S;

    for(int i = 0; i < S.size(); i++){
        buff = (int)S[i];
        buff = buff + N;
        if(buff > 90){
            buff = buff -26;
        }
        S[i] = buff;
        std::cout << S[i];
    }


}