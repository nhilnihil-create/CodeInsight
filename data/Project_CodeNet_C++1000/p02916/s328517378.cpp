#include<vector>
#include<iostream>
using namespace std;

int main(){
    int N, b;
    int ans = 0;

    std::cin >> N;
    vector<int> A(N), C(N-1);

    for(int i = 0; i < N; i++){
        std::cin >> A[i];
    }

    for(int i=0; i < N; i++){
        std::cin >> b;
        ans = ans + b;
    }

    for(int i=0; i < N-1; i++){
        std::cin >> C[i];
    }

    int a_prev = A[0];
    for(int i = 1; i < N; i++){
        if(A[i] == a_prev + 1){
            ans = ans + C[a_prev-1];
        }
        a_prev = A[i];
    }

    std::cout << ans;

}
