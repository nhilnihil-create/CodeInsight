#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M; cin >> N >> M;
    priority_queue<long long> que;
    long long A;
    for(int i = 0; i < N; i++){
        cin >> A; que.push(A);
    }
    
    for(int i = 0; i < M; i++){
        long long p = que.top(); que.pop();
        p /=2;
        que.push(p);
    }
    int Size = que.size();
    long long ans = 0;
    for(int i = 0; i < Size; i++){
        long long q = que.top(); que.pop();
        ans += q;
    }
    
    cout << ans << endl;
    return 0;
}
