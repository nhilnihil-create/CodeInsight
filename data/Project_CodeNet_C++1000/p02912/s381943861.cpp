#include<bits/stdc++.h>
using namespace std;
using li = long int;

int N, M, a, val;
li res = 0;
vector<int> A(100010);
priority_queue<int> pq;

int main(){
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){ cin >> A[i]; pq.push(A[i]); }
    for(int i = 0; i < M; i++){ val = pq.top(); pq.pop(); pq.push(val/2); }
    while(!pq.empty()){ res += pq.top(); pq.pop(); }
    
    cout << res << endl;
    return 0;
}