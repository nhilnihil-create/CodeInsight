#include <iostream>

using namespace std;

int insertionSort(int *A, int n, int g){
    int count = 0;
    for(int i = g; i < n; i++){
        int v = A[i];
        int j = i - g;
        while(j >= 0 && A[j] > v){
            A[j+g] = A[j];
            j = j - g;
            count++;
        }
        A[j+g] = v;
    }
    return count;
}

void shellSort(int *A, int n){
    int i, count = 0;
    int m = 100;
    int G[m];
    G[0] = 1;
    for(i = 1; i < m; i++){
        G[i] = 3 * G[i-1] + 1;
        if(G[i] > n) break;
    }
    m = i;
    for(int h = 0, i = m-1; i >= 0; i--){
        G[i] = 3 * h + 1;
        h = 3 * h + 1;
    }
    for(i = 0; i < m; i++) count += insertionSort(A, n, G[i]);

    cout << m << endl;
    for(i = 0; i < m - 1; i++) cout << G[i] << " ";
    cout << G[i] << endl;
    cout << count << endl;
}

int main(){
    int n, i;
    cin >> n;
    int A[n];
    for(i = 0; i < n; i++) cin >> A[i];
    shellSort(A, n);
    for(i = 0; i < n-1; i++) cout << A[i] << endl;
    cout << A[i] << endl;
    return 0;
}
