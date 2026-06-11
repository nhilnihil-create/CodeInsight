#include <bits/stdc++.h>
int main(void){
    // Your code here!
    
    int N, K;
    std::cin >> N >> K;
    std::vector<int> A(N);
    for(int i=0; i<N; ++i) std::cin >> A.at(i);
    
    for(int i = 0; i < K; ++i) {
        // sousa
        std::vector<int> next(N + 1);
        for(int j = 0; j < N; ++j) {
            int left = std::clamp(j - A[j], 0, N - 1);
            int right = std::clamp(j + A[j], 0, N - 1);
            ++next[left];
            --next[right + 1];
        }
        for(int j = 1; j <= N; ++j) next[j] += next[j - 1];
        
        int cntN = 0;
        for(int j = 0; j < N; ++j) { cntN += next[j] == N; A[j] = next[j]; }
        if (cntN == N) break;
    }
    for(int i = 0; i < N; ++i) {
        std::cout << A[i];
        std::cout << (i == N - 1 ? "\n" : " ");
    }
}
