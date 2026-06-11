#include<iostream>
using namespace std;

int cnt;

void insertionSort(int* a, int n, int g){

    int i, j, v;

    for(i = g; i < n; i++){
        v = a[i];
        j = i - g;
        while((j >= 0) && (a[j] > v)){
            a[j + g] = a[j];
            j = j - g;
            cnt++;
        };
        a[j + g] = v;
    }
}

void shellsort(int* a, int n)
{
    cnt = 0;
    int i, p;
    int m;
    int* G;

    p = 1;
    for(i = 1; i < 20; i++){
        p = p * 3;
        if(p - 1 > 2 * n) break;
    }
    if(i > 1) i = i - 1;
    m = i;

    G = new int [m];
    if(G == NULL) return;

    p = 1;
    for(i = 0; i < m; i++){
        p = p * 3;
        G[m - 1 - i] = (p - 1) / 2;
    }
    cout << m << endl;
    for(i = 0; i < m - 1; i++) cout << G[i] << " ";
    cout << G[m - 1] << endl;

    for(int i = 0; i < m; i++){
        insertionSort(a, n, G[i]);
    }
    delete [] G;
}

int main()
{
    int* A;
    int i, n;
    cin >> n;

    A = new int [n];
    if(A == NULL) return 0;

    for(i = 0; i < n; i++) cin >> A[i];

    shellsort(A, n);
    cout << cnt << endl;
    for(i = 0; i < n; i++) cout << A[i] << endl;

    delete [] A;

    return 0;
}