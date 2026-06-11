#include <iostream>
using namespace std;

int cnt = 0;

void insertionSort(int A[], int n, int g) {
    for (int i = g; i < n; ++i) {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j + g] = A[j];
            j -= g;
            ++cnt;
        }
        A[j + g] = v;
    }
}

int main() {
    int n, A[1000000];
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> A[i];

    int m = 1, G[20];
    G[0] = n / 2;
    for (int i = 0; G[i] > 1; ++i) {
        G[i + 1] = G[i] / 2;
        ++m;
    }
    for (int i = 0; i < m; ++i) insertionSort(A, n, G[i]);

    cout << m << endl;
    for (int i = 0; i < m; ++i) {
        if (i) cout << ' ';
        cout << G[i];
    }
    cout << endl << cnt << endl;
    for (int i = 0; i < n; ++i) cout << A[i] << endl;

    return 0;
}
