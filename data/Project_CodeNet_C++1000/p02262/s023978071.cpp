#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

int tst_count;

void inserSort(int A[], int n, int g){
    if (g > n) return;
    for (int i = g; i < n; i++) {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j + g] = A[j];
            j = j - g;
            tst_count++;
        }
        A[j + g] = v;
    }
}

void shell(int A[],int n){
    tst_count = 0;
    int m = 13;
    int G[13] = {1,4,13,40,121,364,1093,3280,9841,29524,88573,265720,797161};
    
    while (G[m-1] > n) {
        m--;
    }

    for (int i = m-1; i >= 0; i--) {
        inserSort(A,n,G[i]);
    }
    
    cout << m << endl << G[m-1];
    for (int i = m-2; i >= 0; i--) {
        cout << " " << G[i];
    }
    cout << endl << tst_count << endl;
}

int main(){
    int n;
    int A[1000001];
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d",&A[i]);
    }
    
    shell(A,n);
    
    for (int i = 0; i < n; i++) {
        printf("%d\n",A[i]);
    }
    
    return 0;
}