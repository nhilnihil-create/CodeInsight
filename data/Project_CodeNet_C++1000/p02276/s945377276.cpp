#include <iostream>
#include <ios>
#include <utility>

using namespace std;

int partition(int A[], int p, int r){
    int x = A[r];
    int i = p - 1;
    for (int j = p; j != r; ++j){
        if (A[j] <= x) swap(A[++i], A[j]);
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}


int main()
{
    ios::sync_with_stdio(false);
    int n = 0;
    cin >> n;
    int A[100000] = {0};
    for (int i = 0; i != n; ++i) cin >> A[i];
    int pivot = partition(A, 0, n - 1);
    for (int i = 0; i != n; ++i){
        if (i == pivot){
            cout << '[' << A[i] << ']';
        }else{
            cout << A[i];
        }
        if (i == n - 1){
            cout << endl;
        }else{
            cout << ' ';
        }
    }
    return 0;
}