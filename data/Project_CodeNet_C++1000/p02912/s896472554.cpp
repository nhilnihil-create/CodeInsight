#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using ll=long long;
int main() {
    int N,M; cin>>N>>M;
    priority_queue<int> q;
    for (int i = 0; i < N; i++){
        int A; cin>>A;
        q.push(A);
    }
    for (int i = 0; i < M; i++){
        if(q.size()){
            int tmp=q.top();
            q.pop();
            if(tmp/2!=0)q.push(tmp/2);
        }else break;
    }
    ll ans=0;
    while(q.size()){
        ans+=q.top();
        q.pop();
    }
    cout<<ans<<endl;
}