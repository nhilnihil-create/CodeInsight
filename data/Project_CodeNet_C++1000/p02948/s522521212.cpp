#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool compair(pair<long long, long long> a, pair<long long, long long> b){
    if(a.first != b.first){
        return a.first > b.first;
    }
    else{
        return a.second > b.second;
    }
}

int main(){
    long long n, m;
    cin >> n >> m;

    vector<vector<long long> > mem(m+1);

    for(long long i = 0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        if(a > m) continue;
        mem[a].push_back(b);
    }

    priority_queue<long long> que;

    long long ans = 0;

    for(long long d = m-1; d >= 0; d--){
        for(long long j = 0; j < mem[m-d].size(); j++) que.push(mem[m-d][j]);

        if(!que.empty()){
            ans += que.top();
            que.pop();
        }
    }
    cout << ans << endl;
    return 0;
}