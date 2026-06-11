#include <bits/stdc++.h>
#include <climits>
#include <sstream>
using namespace std;

int main() {
    
    int N,K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N;i++)cin >> A[i];
    
    //bool flag;
    for(int i = 0; i < K;i++){
        vector<int> B(N,0);
        for(int j = 0; j < N;j++){
            int l = max(0,j-A[j]);
            int r = min(N-1,j+A[j]);
            B[l]++;
            if(r+1<N)B[r+1]--;
        }
        int sum = B[0];
        for(int i = 1; i < N;i++){
            B[i]+=B[i-1];
            sum += B[i];
        }
        for(int i = 0; i < N;i++){
            A[i] = B[i];
        }
        
        if(sum == N*N)break;
    }
    
    for(int i = 0; i < N;i++){
        if(i!=N-1)cout <<A[i] <<" ";
        else cout << A[i] << endl;
    }
}
