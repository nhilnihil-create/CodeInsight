#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
#define INF = 1000000100;

int main(){
    int N;
    cin >> N;
    vector<vector<int >> G(N);
    vector<pair<int, int>> vp;
    for(int i=1;i<N;i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
        vp.emplace_back(a,b);        
    }
    int K=0;
    map<pair<int ,int>, int> I;
    vector<int> cs(N, 0);

    vector<bool> used(N, false);
    queue<int > que;
    used[0]=true;
    que.emplace(0);
    while(!que.empty()){
        int v=que.front(); que.pop();
        if(K<(int) G[v].size()) K=(int) G[v].size();
        int cur = 1;
        for(int u : G[v]){
            if(used[u]) continue;
            if(cur==cs[v]) cur++;
            cs[u] = I[make_pair(u,v)]=I[make_pair(v,u)] = cur++;
            que.emplace(u);
            used[u]=true;
        }
    }

    cout << K << endl;
    for(auto p: vp){
        cout << I[p] << endl;
    }
    return 0;

}