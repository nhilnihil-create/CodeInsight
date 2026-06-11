#include <iostream>

#define N_MAX 2001
#define DIVISOR 1000000007

int main(void) {
    int s, S;
    int A[N_MAX];
    
    std::cin >> S;
    
    A[1] = 0;
    A[2] = 0;
    A[3] = 1;
    
    if (S != 1 && S != 2 && S != 3) {
        for(s = 4; s <= S; s++) {
            A[s] = (A[s-1] + A[s-3]) % DIVISOR;
        }
    }
    
    std::cout << A[S] << std::endl;
    
    return 0;
}