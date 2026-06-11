#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int INF = 1001001001;
vector<vector<int> > to(100005);
vector<int> check(100005, INF);
vector<int> check1(100005, INF);
vector<int> check2(100005, INF);


/*void kenkenpa(int v, int x, int k){
    if(x == 3){
        k++;
        if(check[v] <= k)return;
        check[v] = k;
    }
    for(int a : to[v]){
        int n = x+1;
        if(x == 3)n = 1;
        kenkenpa(a, n, k);
    }
    return;
}*/

int main() {
    int N, M; cin >> N >> M;
    rep(i, M){
        int u, v; cin >> u >> v;
        u--; v--;
        to[u].push_back(v);
    }

    int S, T; cin >> S >> T;
    S--; T--;
    
    queue<int> Q;
    for(int p : to[S]){
        Q.push(p);
    }

    check[S] = 0;
    int cnt = 1;
    while(!Q.empty()){
        queue<int> Q2;
        while(!Q.empty()){
            int x = Q.front(); Q.pop();
            if(check1[x] != INF)continue;
            check1[x] = cnt;
            for(int p : to[x]){
                Q2.push(p);
            }
        }
        queue<int> Q3;
        while(!Q2.empty()){
            int x = Q2.front(); Q2.pop();
            if(check2[x] != INF)continue;
            check2[x] = cnt;
            for(int p : to[x]){
                Q3.push(p);
            }
        }
        while(!Q3.empty()){
            int x = Q3.front(); Q3.pop();
            if(check[x] != INF)continue;
            check[x] = cnt;
            for(int p : to[x]){
                Q.push(p);
            }
        }
        cnt++;
    }

    if(check[T] == INF){
        cout << -1 << endl;
    } else {
        cout << check[T] << endl;
    }

    return 0;
}