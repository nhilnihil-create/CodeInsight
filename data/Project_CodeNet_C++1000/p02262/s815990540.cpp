#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long cnt;
int n;
int A[1000000];
vector<int> G;

void insertionSort(int A[], int n, int g) {
    for (int i = g; i < n; i++) {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j + g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j + g] = v;
    }
}

void shellSort(int A[], int n) {
    for (int a = 1; ;) {
        if (a > n) break;
        G.push_back(a);
        a = a * 3 + 1;
    }

    for (int i = G.size() - 1; i >= 0; i--) {
        insertionSort(A, n, G[i]);
    }
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    cnt = 0;

    shellSort(A, n);

    cout << G.size() << endl;
    for (int i = G.size() - 1; i >= 0; i--) {
        cout << G[i];
        if (i == 0) cout << endl;
        else cout << ' ';
    }
    cout << cnt << endl;

    for (int i = 0; i < n; i++) {
        cout << A[i] << endl;
    }

    return 0;
}