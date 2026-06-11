#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int N, M, Q;
vector<int> a, b, c, d;
long long ans;
long long res, res2;
vector<int> num;
long long dfs(int i, int u){
    long long t2 = 0;
    if(u == N){
        long long t = 0;
        for(int j = 0; j < Q; j++){
            if(num[b[j] -1] -  num[a[j] - 1] == c[j]) t += d[j];
        }
        return t;
    }
    num[u] = i;
    for(int j = 0; j  + i <= M; j++){
        t2 = max(t2, dfs(i+j, u + 1));
    }
    return t2;
}
int main(){
    cin >> N >> M >> Q;
    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);
    for(int i = 0; i < Q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    ans = 0;
    num.resize(N);
    for(int i = 1; i <= M; i++){
        ans = max(ans, dfs(i, 0));
    }
    cout << ans << endl;
}
