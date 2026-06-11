#include <iostream>

int insertionSort(int A[], int n, int g) {
    int j;
    int cnt = 0;
    for (int i=g; i<n; i++) {
        int v = A[i];
        j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j+g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j+g] = v;
    }
    return cnt;
}

int shellSort(int A[], int n) {
    int m = n;
    int G[25];
    int i=0;
    int cnt=0;
    
    while (true) {
        G[i] = m;
        if (m == 1)
            break;
        else
            m /= 2;
        i++;
    }
    
    std::cout << i+1 << std::endl;

    for (int j=0; j<=i; j++) {
        std::cout << G[j] << " ";
        cnt += insertionSort(A, n, G[j]);
    }
    std::cout << std::endl;
    return cnt;
}

int main() {
    int A[1000000];
    int n;

    // input
    std::cin >> n;
    for (int i=0; i<n; i++) std::cin >> A[i];

    // sort
    int cnt = shellSort(A, n);
    
    // output
    std::cout << cnt << std::endl;
    for (int i=0; i<n; i++) std::cout << A[i] << std::endl;

    return 0;
}

