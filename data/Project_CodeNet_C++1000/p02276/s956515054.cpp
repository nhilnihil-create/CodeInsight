#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &A, int p, int r) {
    int x, i;
    x = A.at(r);
    i = p - 1;
    for (int j = p; j < r; j++) {
        if (A.at(j) <= x) {
            swap(A.at(++i), A.at(j));
        }
    }
    swap(A.at(++i), A.at(r));

    return i;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A.at(i));
    }

    int j = partition(A, 0, n - 1);

    for (int i = 0; i < n - 1; i++) {
        if (i == j) {
            printf("[%d] ", A.at(i));
        } else {
            printf("%d ", A.at(i));
        }
    }
    printf("%d\n", A.at(n - 1));
}
