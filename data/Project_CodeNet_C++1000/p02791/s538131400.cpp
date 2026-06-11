#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long N;
    // vector<long long> P_list[N];
    // vector<long long> judge[N];
    long long P, min_P = 200001;
    long long count = 0;
    std::cin >> N;

    for(long long i = 0; i<N; i++){
        std::cin >> P;
        if(P < min_P){
            min_P = P;
        }
        if(P <= min_P){
            count++;
        }
    }
    std::cout << count;
}
