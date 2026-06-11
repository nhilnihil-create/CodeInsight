#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &A, int p, int r){
    int x = A[r];
    int i = p-1;
    for(int j=p; j<=r-1; ++j){
        if(A[j] <= x ){
            i = i+1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);

    return i+1;
}


int main()
{
    int n;
    cin >> n;
    vector<int> A(n,0);
    for(auto&& x : A){
        cin >> x;
    }

    int q = partition(A,0,n-1);
    for(int i=0; i<q; ++i){
        if(i>0){
            cout << ' ';
        }
        cout << A[i];
    }

    cout << " [" << A[q] << "]";

    for(int i=q+1; i<n; ++i){
        if(i>0){
            cout << ' ';
        }
        cout << A[i];
    }
    cout << endl;

    return 0;
}
