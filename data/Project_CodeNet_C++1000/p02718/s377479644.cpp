#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

#define ll long long

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    int sum = 0;
    for(int i=0; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
    }

    std::sort(A.begin(), A.end());

    bool is_select = true;
    int border = sum / (4 * M);
    for(int i=0; i < M; i++) {
        if(sum % (4*M) == 0) {
            if(border > A[N-1-i]) {
                is_select = false;
                break;
            }
        }
        else {
            if(border >= A[N-1-i]) {
                is_select = false;
                break;
            }
        }
    }

    if(is_select) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
}