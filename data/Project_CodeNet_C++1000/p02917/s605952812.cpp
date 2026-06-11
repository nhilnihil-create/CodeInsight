#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> A, B;

int main(){
    cin >> N;
    A.resize(N);
    B.resize(N-1);
    for(int i = 0; i < N-1; ++i) cin >> B[i];
    for(int i = 0; i < N; ++i){
        if(i == 0) A[i] = B[i];
        else if(i == N-1) A[i] = B[i-1];
        else{
            A[i] = min(B[i-1], B[i]);
        }
    }
    int ans = 0;
    for(int i = 0; i < A.size(); ++i){
        ans += A[i];
    }
    cout << ans << endl;
    return 0;
}