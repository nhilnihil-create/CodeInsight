#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
using ll = long long;

int main(){
    int N,K;
    cin >>N>>K;
    vector<vector<int>> graph(N,vector<int>());
    vector<ll> muls(N,-1);
    queue<pair<int,int>> q;
    
    for(int i = 0;i < N-1;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    muls[0] = K;
    for(int i  = 0;i < graph[0].size();i++){
        muls[graph[0][i]] = K-1-i;
        q.push(pair<int,int>(graph[0][i], 0));
    }
    while(q.size() > 0){
        pair<int,int> p = q.front();q.pop();
        int point = p.first;int parent = p.second;
        int cnt = 0;
        for(int i = 0;i < graph[point].size();i++){
            if(graph[point][i] == parent)continue;
            muls[graph[point][i]] = K-2-cnt;
            q.push(pair<int,int>(graph[point][i],point));
            cnt++;
        }
    }
    int res = 1;
    for(int i = 0;i < N;i++){
        res = (res * muls[i]) % (int)(1e9+7);
    }
    cout << res << endl;

}