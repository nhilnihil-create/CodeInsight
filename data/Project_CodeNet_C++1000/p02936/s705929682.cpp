#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<set>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
#define INF 1000000100
#define rep(i,n) for (int i=0;i<n;i++)

const int maxN=2*100005;
int N;
vector<int> G[maxN];
vector<int> c(maxN);

void add_edge(int a, int b){
    G[a].push_back(b);
    G[b].push_back(a);
}

void bfs(){
    queue<int> q;
    bool used[N];
    rep(i,N) used[i]=false;
    q.push(0);
    while(!q.empty()){
        int now = q.front();q.pop();
        used[now]=true;
        rep(i,G[now].size()){
            int v=G[now][i];
            if(used[v]) continue;
            c[v] += c[now];
            q.push(v);
        }
    }
}

int main(){
    int Q;
    cin >> N >> Q;
    rep(i,N-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        add_edge(a,b);
    }

    rep(i,Q){
        int p,x;
        cin >> p >> x;
        c[--p] += x;
    }
    bfs();

    rep(i,N){
        cout << c[i] << " " ;
    }
    cout << endl;
    return 0;
}


