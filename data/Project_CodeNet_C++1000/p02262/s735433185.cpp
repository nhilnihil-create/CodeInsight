#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> getGapArray(int n) {
    std::vector<int> gaps;
    gaps.push_back(1);
    for (int h = 4; h < n; h = 3 * h + 1) {
        gaps.push_back(h);
    }
    std::reverse(gaps.begin(), gaps.end());
    return gaps;
}

int insertionSort(std::vector<int>& A, int g) {
    int cnt = 0;
    int v, j;
    for (int i = g; i < A.size(); i++) {
        v = A[i];
        j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j + g] = A[j];
            j -= g;
            cnt++;
        }
        A[j + g] = v;
    }
    return cnt;
}

int shellSort(std::vector<int>& A, std::vector<int>& G) {
    int cnt = 0;
    for (int i = 0; i < G.size(); i++) {
        cnt += insertionSort(A, G[i]);
    }
    return cnt;
}

int main(int argc, const char *argv[]) {
    int n;
    std::cin >> n;
    std::vector<int> A(n);
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    
    std::vector<int> G = getGapArray(n);
    int cnt = shellSort(A, G);
    
    std::cout << G.size() << std::endl;
    std::cout << G[0];
    for (int i = 1; i < G.size(); i++) {
        std::cout << " " << G[i];
    }
    std::cout << std::endl;
    std::cout << cnt << std::endl;
    for (int i = 0; i < A.size(); i++) {
        std::cout << A[i] << std::endl;
    }
    
    return 0;
}