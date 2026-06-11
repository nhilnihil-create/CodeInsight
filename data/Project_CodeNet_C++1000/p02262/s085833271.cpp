#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> G;
int A[1000000];
long long cnt = 0;

void insertionSort(int A[], int n, int g)
{
    for (int i = g; i < n; i++)
    {
        int temp = A[i];
        int j = i - g;
        while ((j >= 0) && (A[j] > temp))
        {
            A[j + g] = A[j];
            j -= g;
            cnt++;
        }
        A[j + g] = temp;
    }
}
void shellSort(int A[], int n)
{
    int i = 1;
    while (i <= n)
    {
        G.push_back(i);
        i = 3 * i + 1;
    }
    for (int i = G.size() - 1; i >= 0; i--)
    {
        insertionSort(A, n, G[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    shellSort(A, n);

    cout << G.size() << endl;
    for (int i = G.size() - 1; i > 0; i--)
    {
        printf("%d ", G[i]);
    }
    printf("1\n");

    printf("%d\n",cnt);

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", A[i]);
    }

    return 0;
}
