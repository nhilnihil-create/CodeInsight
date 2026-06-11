#include <bits/stdc++.h>
using namespace std;

int main() {

    int n,m;
    cin >> n >> m;

    priority_queue<long long> que;

    for (int i = 0; i < n; i++){
        long long ai;
        cin >> ai;
        que.push(ai);
    }

    for (int i = 0; i < m; i++){
        long long t;
        t=que.top();
        que.pop();
        que.push(t/2);
    }

    long long ans=0;
    while(!que.empty()){
        ans+=que.top();
        que.pop();
    }

    cout << ans << endl;
}



