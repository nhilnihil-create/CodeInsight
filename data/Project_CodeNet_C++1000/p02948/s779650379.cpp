#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;

int main() {
    int N,M;
    cin>>N>>M;
    vector<vi> work_list(100001);
    for (int i = 0; i < N; i++){
        int A,B;cin>>A>>B;
        work_list[A].push_back(B);
    }
    priority_queue<int> q;
    int ans=0;
    for (int i = 1; i <=M; i++){
        for(auto x:work_list[i])q.push(x);
        if(q.size()){
            ans+=q.top();
            q.pop();
        }
    }
    cout<<ans<<endl;
}