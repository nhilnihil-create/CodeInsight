#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long N, M, K;
    long long A_tmp, B_tmp;
    long long A_start, A_pos;
    long long ans;
    std::cin >> N >> M >> K;
    vector<long long> A(N+1), B(M+1);

    A[0] = 0;
    B[0] = 0;

    for(long long i = 1; i <= N; i++){
        if(i == 1){
            std::cin >> A[i];
        }else{
            if(A[i-1] >= 1000000000){
                A[i] = 1000000001;
                std::cin >> A_tmp;
            }else{
                std::cin >> A_tmp;
                A[i] = A[i-1] + A_tmp;
            }
        }
        //debug
        // std::cout << A[i] << " ";
    }
    // for(int i = 0; i < N+1; i++){
    //     std::cout << A[i] << " ";
    // }
    // std::cout << M;

    for(long long i = 1; i <= M; i++){
        // std::cout << i << "\n"; 
        if(i == 1){
            std::cin >> B[i];
        }else{
            if(B[i-1] >= 1000000000){
                B[i] = 1000000001;
                std::cin >> B_tmp;
            }else{
                std::cin >> B_tmp;
                B[i] = B[i-1] + B_tmp;
            }
        }
        // std::cout << B[i] << " ";
    }

    //B=0のときのAの最大値
    for(int i = N; i >= 0; i--){
        if(A[i] <= K){
            A_start = A[i];
            A_pos = i;
            ans = A_pos;
            // std::cout << ans << "\n";
            break; 
        }
    }

    for(int i = 0; i < M + 1; i++){
        // i + 1はBの冊数
        B_tmp = B[i];
        for(int j = A_pos; j >= 0; j--){
            // std::cout << A[j] << " " << B_tmp << "\n";
            if(B_tmp + A[j] <= K){
                A_pos = j;
                if(ans < i + j){
                    ans = i + j;
                    // std::cout << i << " " << j << "\n";
                }
                break;
            }
        }
    }

    std::cout << ans;

}