#include<bits/stdc++.h>
using namespace std;
int MIN=9999;
string S;
long long int MOD = 1000000007;
const int MAX = 1000001;
long long int fac[MAX],finv[MAX], inv[MAX];

void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i=2;i<MAX;i++){
        fac[i] = fac[i-1]* i % MOD;
        inv[i] = MOD - inv[MOD%i]*(MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

long long COM(int n,int k){
    if(n < k)return 0;
    if(n < 0 || k< 0)return 0;
    return fac[n]*(finv[k]*finv[n-k] % MOD) % MOD;
}

int main(){
    long long int N,K,p[200001],k[200001];

    
    cin >> N >> K;
    int a,b;
        vector<vector<int> > graph = vector<vector<int> >(N+1,vector<int>(0));
    for(int i=0;i<N-1;i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<pair<int,int> > que;
    que.push(make_pair(0,1));
    for(int i=0;i<200000;i++)
        p[i] = 0;
    while(!que.empty()){
        pair<int,int> target = que.front();
        int parent = target.first;
        int node = target.second;
        que.pop();
        long long int iro = p[node];
        long long int point = K - iro;
        if(node != 1){
            point--;
        }
        if(parent != 1 && node != 1){
            point--;
        }
        k[node] = point;
        int is = 0;
        for(int i=0;i<graph[node].size();i++){
            if(graph[node][i] == parent)
                continue;
            else{
                int ns = graph[node][i];
                p[ns] = is;
                is++;
                que.push(make_pair(node,ns));
            }
        }
    }
    long long int res=1;
    for(int i=1;i<=N;i++){
        res = (res*k[i]) % MOD;
    }
    cout << res << endl;
    return 0;
}