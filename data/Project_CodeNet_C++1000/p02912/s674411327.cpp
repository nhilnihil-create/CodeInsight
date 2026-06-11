#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N,M; cin >> N >> M;
    priority_queue<long long> que;
    for(int i = 0; i < N; i++){
        long long a; cin >> a;
        que.push(a);   
    }
    for(int i = 0; i < M; i++){
        long long b = que.top();
        que.pop();
        que.push(b/2);
    }
    long long sum = 0;
    while(!que.empty()){
        sum += que.top();
        //cout << que.top() << endl;
        que.pop();
    }
    cout << sum << endl;
}
