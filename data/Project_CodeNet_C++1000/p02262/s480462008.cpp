#include<cstdio>
#include<algorithm>
#include<vector>

#define MAX_N 1000000

using namespace std;

long long A[MAX_N];
vector<int> G;
int cnt = 0;

void printNums(int n)
{
    for (int i = 0; i < n; i++) {
        printf("%lld\n", A[i]);
    }
}

void getG(int n)
{
    int k = 1;
    while(k <= n) {
        G.push_back(k);
        k = 3 * k + 1;
    }
}

void insertSort(int n, int interval)
{
    int i, j, pivot;
    for (i = interval; i < n; i++) {
        pivot = A[i];
        j = i - interval;
        while((j >= 0) && (A[j] > pivot)) {
            A[j + interval] = A[j];
            j -= interval;
            cnt++;
        }
        A[j + interval] = pivot;
    }
}

int main()
{
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
    }

    getG(n);
    printf("%d\n", G.size());
    for (i = G.size() - 1; i > 0; i--) {
        printf("%d ", G[i]);
    }
    printf("%d\n", G[0]);

    for (i = G.size() - 1; i >= 0; i--) {
        insertSort(n, G[i]);
    }
    printf("%d\n", cnt);
    printNums(n);
}