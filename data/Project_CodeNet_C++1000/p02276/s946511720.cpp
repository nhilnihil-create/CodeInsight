#include<iostream>
using namespace std;


int partition(int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++){
        if (A[j] <= x) {
            i += 1;
            int t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    int t = A[i+1];
    A[i+1] = A[r];
    A[r] = t;
    for (int k = 0; k < r+1; k++){
        if(k) cout << " ";
        if (k == i + 1){
            cout << "[" << A[i+1] << "]" ;
        } else {        
            cout << A[k];
        }
    }
    return i + 1;
    
}

int main()
{
    int n, A[100000];
    
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    partition(A, 0, n-1);
    cout << endl;
    
    return 0;
}