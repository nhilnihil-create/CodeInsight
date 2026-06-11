#include<iostream>
#include<vector>
using namespace std;


int main(){
    int N, p;
    int count = 0;

    std::cin >> N;
    for(int i = 0; i < N; i++){
        std::cin >> p;
        if(p != i + 1){
            count++;
        }
    }

    if(count <= 2){
        std::cout << "YES";
    }else{
        std::cout << "NO";
    }
}