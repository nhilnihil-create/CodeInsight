#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int seen[100005][3];
vector<int> graph[100005];

int main(){
    int n,m;
    cin >> n >> m;
    rep(i,n)rep(j,3) seen[i][j] = -1;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        --a;--b;
        graph[a].push_back(b);
    }
    int s,t;
    cin >> s >> t;
    --s;--t;
    queue<pair<int,int>> q;
    q.push(P(3*s+0,0));
    while(!q.empty()){
        int now = q.front().first / 3;
        int c = q.front().first % 3;
        int len = q.front().second;
        q.pop();
        if(seen[now][c]>=0) continue;
        seen[now][c] = len;
        c = (c+1)%3;
        for(int j:graph[now]){
            if(seen[j][c]>=0) continue;
            q.push(P(3*j+c,len+1));
        }
    }
    if(seen[t][0]>=0) cout << seen[t][0] / 3 << endl;
    else cout << -1 << endl;
    return 0;
}