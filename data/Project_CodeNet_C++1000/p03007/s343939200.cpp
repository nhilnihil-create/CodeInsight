#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int A[100010];

int main(void){
    int N;
    cin >> N;
    for(int i=0; i<N; ++i) cin >> A[i];
    sort(A, A+N);
    int ans=A[N-1]-A[0];
    for(int i=1; i<N-1; ++i) ans += abs(A[i]);
    cout << ans << endl;
    for(int i=N-2; i>=0; --i){
        if(A[i]>0){
            cout << A[0] << ' ' << A[i] << endl;
            A[0] -= A[i];
        }
        else{
            cout << A[N-1] << ' ' << A[i] << endl;
            A[N-1] -= A[i];
        }
    }
    return 0;
}

