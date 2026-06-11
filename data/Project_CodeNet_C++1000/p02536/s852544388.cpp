#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
#define rep(i,n) for(lint (i)=0;(i)<(n);(i)++)
#define repp(i,m,n) for(lint (i)=(m);(i)<(n);(i)++)
#define repm(i,n) for(lint (i)=(n-1);(i)>=0;(i)--)
#define INF (1ll<<60)
#define all(x) (x).begin(),(x).end()
const lint MOD =1000000007;
const lint MAX = 1000000;
using Graph =vector<vector<lint>>;
typedef pair<lint,lint> P;
typedef map<lint,lint> M;
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)

 
lint fac[MAX], finv[MAX], inv[MAX];
 
void COMinit() 
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (lint i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
long long COM(lint n, lint k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 
lint primary(lint num)
{
    if (num < 2) return 0;
    else if (num == 2) return 1;
    else if (num % 2 == 0) return 0;
 
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
 
    return 1;
}
   long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
    lint lcm(lint a,lint b){
        return a/__gcd(a,b)*b;
    }
     lint gcd(lint a,lint b){
        return __gcd(a,b);
    } 
    struct UnionFind {
    vector<lint> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<lint> siz;

    UnionFind(lint N) : par(N),siz(N,1LL) { //最初は全てが根であるとして初期化
        for(lint i = 0; i < N; i++) par[i] = i;
    }

    lint root(lint x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(lint x, lint y) { // xとyの木を併合
        lint rx = root(x); //xの根をrx
        lint ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        siz[ry]+=siz[rx];
    }

    bool same(lint x, lint y) { // 2つのデータx, yが属する木が同じならtrueを返す
        lint rx = root(x);
        lint ry = root(y);
        return rx == ry;
    }
    lint size(lint x){
        return siz[root(x)];
    }
    void init(lint N){
        for(lint i = 0; i < N; i++) par[i] = i;
        for(lint i = 0; i < N; i++) siz[i] = 1;
    
    }
};
    int main(){
        lint n,m;
        cin>>n>>m;
        UnionFind uf(n);
        rep(i,m){
            lint a,b;
            cin>>a>>b;
            --a;--b;
            uf.unite(a,b);
        }
        set<lint> st;
        rep(i,n)st.insert(uf.root(i));
        cout<<st.size()-1<<endl;
        
    }
      