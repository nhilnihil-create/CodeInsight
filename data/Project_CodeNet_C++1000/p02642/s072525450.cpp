#include <iostream>

int A[200001] ={};
int n_divisor[1000001] ={};

int main() {
    int N;
    std::cin >> N;
    for (int i=1; i<=N; i++) {
        std::cin >> A[i];
    }

    for (int i=1; i<=N; i++) {
        n_divisor[A[i]]++;
        if (n_divisor[A[i]] == 1) {
            for (int j=2; A[i]*j<=1000000; j++) {
                n_divisor[A[i]*j]++;
            }
        }
    }
    int count = 0;
    for (int i=1; i<=N; i++) {
        if (n_divisor[A[i]] == 1) {
            count++;
        }
    }
    std::cout << count << std::endl;
}