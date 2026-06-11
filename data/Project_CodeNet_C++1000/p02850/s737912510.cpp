#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 3000000000000000000; //3*10^18
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int N; cin >> N;
    map<pair<int,int>,int> color;
    vector<vector<int>> G(N+1);
    vector<pair<int,int>> edge(N-1);
    int tmp1,tmp2;
    for (int i = 0; i < N-1; i++) {
        cin >> tmp1 >> tmp2;
        edge[i] = make_pair(tmp1, tmp2);
        G[tmp1].push_back(tmp2);
        G[tmp2].push_back(tmp1);
    }
    
    queue<int> bfs;
    vector<int> fin(N+1,-1);
    bfs.push(1);
    fin[1] = 0;
    int tmp, tmpp, cnt;
    while(!bfs.empty()){
        cnt = 1;
        tmp = bfs.front();
        bfs.pop();
        tmpp = fin[tmp];
        for(int i : G[tmp]){
            if(fin[i] != -1){
                continue;
            }
            else{
                if(cnt == tmpp) cnt++;
                fin[i] = cnt;
                if(tmp < i){
                    color[make_pair(tmp, i)] = cnt;
                }
                else{
                    color[make_pair(i, tmp)] = cnt;
                }
                cnt++;
                bfs.push(i);
            }
        }
    }
    cnt = 0;
    for (int i = 0; i < N-1; i++) {
        cnt = max(cnt, color[edge[i]]);        
    }
    printf("%d\n", cnt);
    for (int i = 0; i < N-1; i++) {
        printf("%d\n", color[edge[i]]);
    }



}
