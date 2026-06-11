#include <iostream>
using namespace std;

int cnt;
void insertionSort(int [], int, int);
void shellSort(int [], int);

void insertionSort(int A[], int n, int g){
    int i, j;
    
    for(i = g; i < n; i++){
        int v = A[i];
        j = i - g;
        
        while(j >= 0 && A[j] > v){
            A[j + g] = A[j];
            j -= g;
            cnt++;
        }
        A[j + g] = v;
    }
}

void shellSort(int A[], int n){
    int m;
    int g;
    int *G;
    int i;
    
    cnt = 0;
    
    for(g = m = 1; 3*g + 1 < n; g = 3*g + 1) m++;
    cout << m << endl;
    
    G = new int[m];
    for(i = 0; i < m; i++){
        G[i] = g;
        if(i) cout << " ";
        cout << G[i];
        g = (g - 1) / 3;
        insertionSort(A, n, G[i]);
    }
    cout << endl;
    delete [] G;
    G = 0;
}

int main(void){
    int n;
    int *input;
    int i;
    
    cin >> n;
    input = new int[n];
    for(i = 0; i < n; i++){
        cin >> input[i];
    }
    
    shellSort(input, n);
    
    cout << cnt << endl;
    for(i = 0; i < n; i++){
        cout << input[i] << endl;
    }
    
    delete [] input;
    input = 0;
    return 0;
}