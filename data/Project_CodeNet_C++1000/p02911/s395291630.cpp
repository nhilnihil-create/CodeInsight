
#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long N, Q, A, K;
    std::cin >> N >> K >> Q;
    vector<long long> points(N, -Q);

    for(long long i = 0; i < Q; i++){
        std::cin >> A;
        points[A-1]++;
    }

    for(long long i = 0; i < N; i++){
        if(points[i] > -K){
            std::cout << "Yes\n";
        }else{
            std::cout << "No\n";
        }
    }

}