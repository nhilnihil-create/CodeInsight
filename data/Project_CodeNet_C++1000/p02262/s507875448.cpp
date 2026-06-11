#include<iostream>
using namespace std;

int cnt = 0;

void scanArray(int n, int* A){
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
}

void printArray(int n, int* A){
    for(int i = 0; i < n; i++){
        cout << A[i] << endl;
    }
}

void printGArray(int m, int* G){
    for(int i = m - 1; i > 0; i--){
        cout << G[i] << " ";
    }
    cout << G[0] << endl;
}

int gArray(int n, int* G){
    G[0] = 1;
    int g = 4;
    int i = 0;
    int m = 1;
    while(g < n){
        m++;
        i++;
        G[i] = g;
        g = 3 * g + 1;
    }
    return m;
}

void insertionSort(int n, int* A, int g){
    for(int i = g; i < n; i++){
        int v = A[i];
        int j = i - g;
        while(j >= 0 && A[j] > v){
            A[j + g] = A[j];
            j = j - g;
            cnt++;
        }
        A[ j + g ] = v;
    }
}

void shellSort(int n, int* A, int m, int* G){
    cnt = 0;
    for(int i = m - 1; i >= 0; i--){
        insertionSort(n, A, G[i]);
    }
}

int main(){
    int n;
    cin >> n;
    int* A = new int[n];
    scanArray(n, A);
    
    int* G = new int[n];
    int m = gArray(n, G);
    cout << m << endl;
    printGArray(m, G);

    shellSort(n, A, m, G);
    cout << cnt << endl;

    printArray(n, A);
    return 0;
}
