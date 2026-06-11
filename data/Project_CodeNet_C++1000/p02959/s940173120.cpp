#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int N;
    std::cin >> N;
    std::vector<long> A(N + 1);
    std::vector<long> B(N);
    
    for (int i = 0; i < N + 1; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }
    
    long result = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (A[i + 1] >= B[i]) {
            result += B[i];
            A[i + 1] = A[i + 1] - B[i];
            B[i] = 0;
        } else {
            result += A[i + 1];
            B[i] = B[i] - A[i + 1];
            A[i + 1] = 0;
        }
        
        if (A[i] >= B[i]) {
            result += B[i];
            A[i] = A[i] - B[i];
            B[i] = 0;
        } else {
            result += A[i];
            B[i] = B[i] - A[i];
            A[i] = 0;
        }
    }
    
    std::cout << result << std::endl;
}
