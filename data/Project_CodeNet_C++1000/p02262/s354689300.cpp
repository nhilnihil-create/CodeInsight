#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

typedef long long ll;

const int MAX = 1000000;
ll cnt;
int l;
int A[MAX];
int n;
vector<int> G;

void insertionSort(int A[], int n, int g) {
    for (int i = g; i < n; i++) {
        int t = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > t) {
            A[j+g] = A[j];
            cnt++;
            j -= g;
        }
        A[j+g] = t;
    }
}

void shellSort(int A[], int n) {
    int h = 1;
    while (h <= n) {
        G.push_back(h);
        h = 3 * h + 1;
    }
    for (int i = G.size() - 1; i >= 0; i--) {
        insertionSort(A, n, G[i]);
    }
}

int main() {
    //freopen("in.txt", "r", "stdin");
    //freopen("out.txt", "w", "stdout");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    shellSort(A, n);
    printf("%lu\n", G.size());
    for (int i = G.size() - 1; i >= 0; i--) {
        if (i < G.size()-1) printf(" ");
        printf("%d", G[i]);
    }
    printf("\n");
    printf("%lld\n", cnt);
    for (int i = 0; i < n; i++) {
        printf("%d\n", A[i]);
    }
    return 0;
}