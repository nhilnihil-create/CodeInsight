#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    //fast_io();

    int N, K; std::cin >> N >> K;
    std::vector<int> A;
    for(int i=0; i<N; i++){
        int b; std::cin >> b; A.push_back(b);
    }

    for(int k=0; k<K; k++){
        std::vector<int> B(N,0);
        for(int i=0; i<N; i++){
            int l=std::max(0,i-A[i]), r=std::min(N-1,i+A[i]);
            B[l]++;
            if(r+1<N) B[r+1]--;
        }
        for(int i=1; i<N; i++) B[i] += B[i-1];
        if(A == B){
            break;
        }else{
            A = B;
        }
    }

    for(int i=0; i<N; i++){
        std::cout << A[i] << " ";
    }
    return 0;
}
