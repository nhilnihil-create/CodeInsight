#include<bits/stdc++.h>
using namespace std;

int main(){
    long long N, M, K;
    cin >> N >> M >> K;
    vector<long long> A(N+1,0), B(M+1,0);
    long long buf, ans = 0, time = 0;
    for(int i = 1; i <= N; ++i){
        cin >> buf;
        A[i] = A[i-1] + buf;
    }
    for(int i = 1; i <= M; ++i){
        cin >> buf;
        B[i] = B[i-1] + buf;
    }
    buf = M;
    for(int i = 0; i <= N; ++i){
        if(A[i] > K)continue;
        time = A[i];
        for(int j = buf; j >= 0; --j){
            if(j==0){
                buf = 0;
                break;
            }
            else if(time + B[j] > K)--buf;
            else break;
        }
        ans = max(ans, i + buf);
    }
    cout << ans << endl;
    return 0;
}