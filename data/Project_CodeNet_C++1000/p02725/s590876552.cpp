#include <bits/stdc++.h>
using namespace std;


int main(void){
   int64_t K,N;
   cin >> K >> N;
   vector<int64_t> A(N);
    for (int i=0;i<N;i++) {
        cin >> A[i];
    }
    int64_t d;
    d=A[0]+K-A[N-1];
    for (int i=0;i<N-1;i++) {
        d=max(d,A[i+1]-A[i]);
    }
   
    cout << K-d << endl;
}


