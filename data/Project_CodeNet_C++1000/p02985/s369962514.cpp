#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

const int MAX = 100005;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < MAX; i++){
                fac[i] = fac[i - 1] * i % MOD;
                inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
                finv[i] = finv[i - 1] * inv[i] % MOD;
        }
}

// 二項係数計算　n kどちらも10**5程度
long long COM(int n, int k){
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long PER(int n,int k){
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        return (fac[n] * finv[n-k]) % MOD;
}


int n = 100005;
int k ;
vector<vector<int>> graph(n,vector<int>());
ll ans = 1;

void dfs(int i,int par){
        if(par == -1) {ans *= PER(k-1,(int)(graph.at(i).size())); }
        else ans *= PER(k-2,(int)(graph.at(i).size())-1);
        
        if(ans >= MOD) ans %= MOD;    
        
        for(int p:graph.at(i)){
                if(p == par) continue;
                dfs(p,i);
        }
}

int main() {
        COMinit();
        cin >> n >> k;
        rep(i,n-1){
                   int a,b;
                cin >> a >> b;
                --a;--b;
                graph.at(a).push_back(b);
                graph.at(b).push_back(a);
        }
        
        if(n==1 && k==1) cout << 1 << endl;
        else if(k == 1) cout << 0 << endl;
        else{
                ans *= k;
                dfs(0,-1);
                cout << ans << endl;
        }
        
        
        return 0;
}


