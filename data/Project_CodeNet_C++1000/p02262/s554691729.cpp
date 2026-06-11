#include<cstdio>
#include<vector>
#define MAX 1000000

using namespace std;

int numbers[MAX], cnt;
vector<int> G;

void insertionSort(int n, int g)
{
    int i, j, pivot;
    for (i = g; i < n; i++) {
        pivot = numbers[i];
        j = i - g;
        while (j >=0 && numbers[j] > pivot) {
            numbers[j + g] = numbers[j];
            j = j - g;
            cnt++;
        }
        numbers[j + g] = pivot;
    }
}

void shellSort(int n)
{
    int h;
    for(h = 1;;) {
        G.push_back(h);
        h = 3 * h + 1;
        if (h > n) break;
    }
    for (int i = G.size() - 1; i >= 0; i--) {
        insertionSort(n, G[i]);
    }
}

int main()
{
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    cnt = 0;
    shellSort(n);
    printf("%d\n", G.size());
    for (i = G.size() - 1; i >= 0; i--) {
        printf("%d", G[i]);
        if (i) printf(" ");
    }
    printf("\n%d\n", cnt);
    for (i = 0; i < n; i++) printf("%d\n", numbers[i]);

    return 0;
}