#include<iostream>
#include<cmath>
using namespace std;

int cnt = 0;
int m = 20;
int G[20] = {};
void insertionsort(int A[], int n, int g){
    for(int i = g; i < n; i++){
        int v = A[i];
        int j = i-g;
        while(j >= 0 && A[j] > v){
            A[j+g] = A[j];
            j = j-g;
            cnt++;
        }
        A[j+g] = v;
    }
}
void shellsort(int A[], int n){
    for (int i = m-1; i >= 0; i--){
       if (i == m-1) G[i] = 1;
       else G[i] = G[i+1]*3 + 1;
    }
    for (int i = 0; i < m; i++){
        insertionsort(A, n, G[i]);
    }
}
int main(){
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    shellsort(A, n);
    int mtrue = 0;
    for (int i = 0; i < m; i++){
        if (G[i] <= n) mtrue++;
    }
    cout << mtrue << endl;
    for (int i = 0; i < m; i++){
        if (G[i] <= n) cout << G[i] << " ";
    }
    cout << endl << cnt << endl;
    for (int i = 0; i < n; i++){
        cout << A[i] << endl;
    }

    return 0;

}
