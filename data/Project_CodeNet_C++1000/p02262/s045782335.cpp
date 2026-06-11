#include <stdio.h>
#include <vector>

using namespace std;

static long long cnt = 0;
static vector<int> G;

static void insertionSort(int A[], int n, int g)
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

static void shellSort(int A[], int n)
{
    for (int h = 1; h <= n;) {
        G.push_back(h);
        h = 3 * h + 1;
    }

    for (int i = (int)G.size() - 1; i >= 0; i--) {
        insertionSort(A, n, G[i]);
    }
}

int main()
{
    int n;
    int A[1000000];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    shellSort(A, n);

    printf("%d\n", (int)G.size());
    for (int i = (int)G.size() - 1; i >= 0; i--) {
        printf("%d", G[i]);
        if (i > 0) {
            printf(" ");
        }
    }
    printf("\n");

    printf("%lld\n", cnt);

    for (int i = 0; i < n; i++) {
        printf("%d\n", A[i]);
    }
    
    return 0;
}

