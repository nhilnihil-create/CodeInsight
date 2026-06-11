#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000001;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int N,M,s,t;
vector<int> graph[100010];

int bfs() {
    vector<vector<int>> dist(N,vector<int>(3,-1));
    dist[s][0] = 0;
    queue<P> que;
    que.push({s,0});
    while(!que.empty()) {
        P p = que.front();
        que.pop();
        for(int i = 0;i < graph[p.first].size();i++) {
            if(dist[graph[p.first].at(i)][(p.second + 1) % 3] == -1) {
                dist[graph[p.first].at(i)][(p.second + 1) % 3] = dist[p.first][p.second] + 1;
                que.push({graph[p.first].at(i),(p.second + 1) % 3});
            }
        }
    }
    if(dist[t][0] == -1) {
        return -1;
    }
    else {
        return dist[t][0] / 3;
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0;i < M;i++) {
        int A,B;
        cin >> A >> B;
        graph[A - 1].push_back(B - 1);
    }
    cin >> s >> t;
    s--;
    t--;
    cout << bfs() << endl;
}