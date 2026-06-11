#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    priority_queue<long long> q;
    for(int i = 0; i < N; i++) {
        long long a;
        cin >> a;
        q.push(a);
    }
    for(int i = 0; i < M; i++){
        long long t = q.top();
        q.pop();
        q.push(t / 2);
    }
    long long ans = 0;
    while(!q.empty()){
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
}