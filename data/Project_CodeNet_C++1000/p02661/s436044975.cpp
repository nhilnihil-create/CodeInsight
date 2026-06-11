#include <bits/stdc++.h>

using namespace std;

int main(){
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    int N;
    cin >> N;
    vector<int> A(N),B(N);
    for(int i=0;i<N; i++){
        cin >> A[i] >> B[i]; 
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    if( N % 2 ){
        cout<< B[N/2] - A[N/2] + 1 << endl;
    }else{
        int start = A[N/2 -1] + A[N/2];
        int end = B[N/2 -1 ] + B[N/2];
        cout << end - start + 1 << endl;
    }

    return 0;
}