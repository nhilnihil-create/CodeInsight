#include <iostream>

long long n_divisors[10000001];

int main()
{
    long long N;
    std::cin >> N;
    for (int i=1; i<=N; i++) {
        for (int j=1; i*j<=N; j++) {
            n_divisors[i*j]++;
        }
    }
    long long result = 0;
    for (int K=1; K<=N; K++) {
        result += K * n_divisors[K];
    }
    std::cout << result << std::endl;
}