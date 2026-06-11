#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MAX_N 200001
int N;
int A[MAX_N];
int B[MAX_N];

int basis(int k){
    return B[(k+1)%N] + B[(k+N-1)%N];
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    vector<int>flag(N, 0); // 確定したら1
    queue<int> que;
    for (int i = 0; i < N; ++i) {
        que.push(i);
        if(A[i] == B[i]) flag[i] = 1;
    }
    ll ans = 0;
    while (! que.empty()){
        int top = que.front();
        que.pop();
        if(flag[top] == 1) continue;
        int ba = basis(top);
        if(ba > B[top]) continue;
        if((B[top] - A[top]) % ba == 0){
            ans += (B[top] - A[top]) / ba;
            B[top] = A[top];
            flag[top] = 1;
        } else{
            ans += B[top] / ba;
            B[top] %= ba;
            if(B[top] < A[top]){
                cout << -1 << "\n";
                return 0;
            }
        }
        que.push((top+1)%N);
        que.push((top+N-1)%N);
    }
    for (int i = 0; i < N; ++i) {
        if(flag[i] == 0) {
            cout << -1 << "\n";
            return 0;
        }
    }
    cout << ans;
    return 0;
}