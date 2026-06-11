#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int A[1000000];
int cnt;
vector<int> G;

void insertion_sort_gap(int A[], int n, int g) 
{
    for (int i = g; i < n; i++) {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j + g] = A[j];
            j -= g;
            cnt++;
        }
        A[j + g] = v;
    }
}

void shell_sort(int A[], int n)
{
    int h = 1;
    while (1) {
        if (h > n) {
            break;
        }
        G.push_back(h);
        h = 3*h + 1;
    }

    for (int i = G.size() - 1; i >= 0; i--) {
        insertion_sort_gap(A, n, G[i]);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    cnt = 0;
    shell_sort(A, n);
    cout << G.size() << endl;
    for (int i = G.size() - 1; i >= 0; i--) {
        printf("%d", G[i]);
        if (i) printf(" ");
    }
    printf("\n%d\n", cnt);
    for (int i = 0; i < n; i++) {
        printf("%d\n", A[i]);
    }

    return 0;
}

