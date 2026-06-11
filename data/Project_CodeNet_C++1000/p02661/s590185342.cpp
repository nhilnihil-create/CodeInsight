#include<bits/stdc++.h>

using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long l, r;
    if(N % 2 == 1){
        l = A[N / 2];
        r = B[N / 2];
    }else{
        l = A[N / 2 - 1] + A[N / 2];
        r = B[N / 2 - 1] + B[N / 2];
    }
    cout << r - l + 1 << endl;
    return 0;
}
