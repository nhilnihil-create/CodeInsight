#include <iostream>
#define MAX 100000

using namespace std;

int A[MAX];

int partition(int p, int r){
    int x = A[r];
    int i = p - 1;
    int tmp;
    for(int j = p; j < r; j++){
        if(A[j] <= x){
            i++;
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    tmp = A[i+1];
    A[i+1] = A[r];
    A[r] = tmp;
    return i+1;
}

int main(){
    int n, i, p;
    cin >> n;
    for(i = 0; i < n; i++) cin >> A[i];
    p = partition(0, n-1);
    for(i = 0; i < n-1; i++){
        if(i == p) cout << "[" << A[i] << "] ";
        else cout << A[i] << " ";
    }
    if(i == p) cout << "[" << A[i] << "]" << endl;
    else cout << A[i] << endl;
    return 0;
}
