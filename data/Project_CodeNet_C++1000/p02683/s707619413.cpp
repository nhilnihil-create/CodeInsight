#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M, X;
    cin >> N >> M >> X;
    vector<int> C(N);
    vector<vector<int>> A(N, vector<int>(M,0));
    priority_queue<int, vector<int>, greater<int>> cost;
    for(int i = 0; i < N; ++i){
        cin >> C[i];
        for(int j = 0; j < M; ++j){
            cin >> A[i][j];
        }
    }
    for(int k = 0; k < pow(2, N); ++k){
        int cost_buf = 0;
        vector<int> Understand(M, 0);
        for(int i = 0; i < N; ++i){ 
            if((k >> i) & 1){ 
                cost_buf += C[i];
                for(int j = 0; j < M; ++j) Understand[j] += A[i][j]; 
            }
        }
        for(int j = 0; j < M; ++j){
            if(Understand[j] < X) break;
            else if(j == M-1) cost.push(cost_buf);
        }
    }
    if(cost.empty()) cout << -1 << endl;
    else cout << cost.top() << endl;
    return 0;
}