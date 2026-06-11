#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N, M;
    cin >> N >> M;
    
    vector<int> A(N);
    int sum = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        sum += A[i];
    }
    
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(A[i]*4*M >= sum) cnt++;
    }
    
    if(cnt >= M) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}