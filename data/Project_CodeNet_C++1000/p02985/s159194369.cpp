#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;

vector<long long int> inverse;
vector<long long int> f, f_inverse;

void factorial_Initialize(int max){
    vector<long long int> a(max+1,1);
    inverse = a;
    f = a;
    f_inverse = a;

    for (int i=2; i<=max; i++){
        inverse[i]   = MOD - inverse[MOD % i] * (MOD / i) % MOD;
        f[i]         = f[i-1]         * i          % MOD;
        f_inverse[i] = f_inverse[i-1] * inverse[i] % MOD;
    }
}

long long int nCr(int n, int r){
    if(n < r || r < 0) return 0;
    if (n >= f.size()){
        factorial_Initialize(n);
    }
    return f[n] * f_inverse[r] % MOD * f_inverse[n-r] % MOD;
}

vector<vector<int>> graph;
long long int k;

int DFS(int v, int parent_v){
    long long int num = 1;
    int children = 0;
    for(int child_v : graph[v]){
        if(child_v == parent_v) continue;

        num *= DFS(child_v, v);
        num %= MOD;
        children += 1;
    }
    num *= nCr(k-2, children);
    num %= MOD;
    num *= f[children];
    num %= MOD;

    return num;
}

int main(){
    int n;
    cin >> n >> k;
    graph.resize(n);
    factorial_Initialize(k);// necessary since might not done in nCr

    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    long long int ans = k;
    int count = 0;
    for(int depth1 : graph[0]){   
        count += 1;
        ans *= DFS(depth1, 0);
        ans %= MOD;   
    }
    ans *= nCr(k-1, count);
    ans %= MOD;
    ans *= f[count];
    ans %= MOD;

    cout << ans << endl;
    return 0;
}