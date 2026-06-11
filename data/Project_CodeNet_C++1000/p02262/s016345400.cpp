#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <utility>
using namespace std;

int cnt;

void trace(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

void insertionSort(int a[], int n, int g)
{
    int v;
    for (int i = 0; i < n; i++)
    {
        v = a[i];
        int j;
        for (j = i - g; j >= 0 && a[j] > v; j = j - g)
        {
            a[j + g] = a[j];
            cnt++;
        }
        a[j + g] = v;
    }
}

void shellSort(int a[], int n)
{
    cnt = 0;
    int m = log2(n)+1;
    int g[m];
    g[0] = n/2+1;
    for(int i = 1; i < m; i++)
        g[i] =  g[i-1]/2;
    for (int i = 0; i < m; i++)
        insertionSort(a, n, g[i]);
    printf("%d\n", m);
    trace(g, m);
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++)
        printf("%d\n", a[i]);
}

int main(void)
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    shellSort(a, n);

    return 0;
}

