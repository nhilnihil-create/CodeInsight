#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

void shellsort(int a[], int n);
void insertionSort(int a[], int n, int g);

long long cnt;
vector<int> G;

int main() {
    int n;
    cin >> n;
    int a[1000000];
    for ( int i = 0; i < n; i++ ) scanf("%d", &a[i]);
    //多くなるかも　速いscanf
    cnt = 0;
    shellsort(a, n);
    cout << G.size() << endl; //line1 m
    for ( int i = G.size() - 1; i >= 0; i-- ) { //line2 m int G[i]
        printf("%d", G[i]);
        if ( i ) printf(" "); //not 0
    }
    printf("\n");
    
    printf("%d\n",cnt); //line3 cnt
    for ( int i = 0; i < n; i++ ) printf("%d\n", a[i]);
    return 0;
}

void shellsort(int a[], int n) {
    for ( int h = 1; ; ) {
        if ( h > n ) break;
        G.push_back(h); //1, 4, 13, 
        h = 3 * h + 1;
    }
    for ( int i = G.size()-1; i >= 0; i-- ) insertionSort(a, n, G[i]);
}

void insertionSort(int a[], int n, int g) {
    for ( int i = g; i < n; i++ ) {
        int v = a[i];
        int j = i - g;
        while ( j >= 0 && a[j] > v) {
            a[j + g] = a[j];
            j -= g;
            cnt++;
        }
        a[j + g] = v;
    }
}
