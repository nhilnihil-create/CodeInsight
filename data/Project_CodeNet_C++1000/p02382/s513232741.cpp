#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
int main() {
    // 配列を受け取る
    int n;
    cin >> n;
    int A[n], B[n];
    for (int i=0;i<n;i++) {
        cin >> A[i];
    }
    for (int i=0;i<n;i++) {
        cin >> B[i];
    }

    int D1=0;
    for (int i=0;i<n;i++) {
        D1+=abs(A[i] - B[i]);
    }
    printf("%d\n", D1);

    int D2=0;
    for (int i=0;i<n;i++) {
        D2+=pow(A[i] - B[i], 2.0);
    }
    printf("%f\n", pow(D2, 0.5));

    long int D3=0;
    for (int i=0;i<n;i++) {
        D3+=pow(abs(A[i] - B[i]), 3.0);
    }
    printf("%f\n", pow(D3, 1.0/3.0));

    int max=0;
    for (int i=0;i<n;i++) {
        if (abs(A[i] - B[i]) > max) {
            max = abs(A[i] - B[i]);
        }
    }
    printf("%d\n", max);
}
