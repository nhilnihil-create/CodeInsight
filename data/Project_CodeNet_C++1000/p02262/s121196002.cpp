#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

long long cnt;
int l;
int A[1000000];
int n;
vector<int> G;

void insertionSort(int A[], int n, int g) {
    for (int i = g; i < n; ++i) {
        int v = A[i];
        int j = i - g;
        while(j >= 0 && A[j] > v)  {
            A[j + g] = A[j];
            j -= g;
            cnt++;
        }
        A[j + g] = v;
    }
}

void shellSort(int A[], int n) {
    int h = 1;
    while(h <= n) {
        G.push_back(h);
        h = 3*h + 1;
    }
    for (int i = G.size() - 1; i >= 0; --i) {
       insertionSort(A, n, G[i]);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    cnt = 0;
    shellSort(A, n);
    cout << G.size() << endl;
    for (int j = G.size() - 1; j >= 0; --j) {
        cout << G[j] << " ";
    }
    cout << endl;
    cout << cnt << endl;
    for (int k = 0; k < n; ++k) {
        cout << A[k] << endl;
    }
}