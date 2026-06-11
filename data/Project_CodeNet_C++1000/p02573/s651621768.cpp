#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
	#define W(x, y) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << y;
#else
	#define W(x, y)
#endif

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vii = vector<pii>;
using vl = vector<ll>;
using vll = vector<pll>;
using ld = long double;
#define ff first
#define ss second
const ld pi = acosl(-1);
const ll prime = 1000000000 + 7;
const ll INF = 1000000000;

struct UnionFind{
    vl pai;
    vl rank;
    vl sum;
    UnionFind(ll n): pai(n), rank(n), sum(n){
        iota(pai.begin(), pai.end(), 0);
        fill(rank.begin(), rank.end(), 1);
        fill(sum.begin(), sum.end(), 1);
    }
    ll Find(ll x){
        if(x == pai[x]){
            return x;
        }
        return pai[x] = Find(pai[x]);
    }
    void Union(ll a, ll b){
        a = Find(a);
        b = Find(b);
        if(a == b){
            return;
        }
        if(rank[a] == rank[b]){
            rank[a]++;
        }
        if(rank[a] < rank[b]){
            sum[b] += sum[a];
            pai[a] = b;
        } else{
            sum[a] += sum[b];
            pai[b] = a;
        }
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ll n, m;
    // while(cin >> n >> m){

    //     UnionFind uf(n*m);
    //     vector<string> vet(n);
    //     for(int i = 0; i < n; ++i){
    //         cin >> vet[i];
    //     }
    //     for(int i = 0; i < n; ++i){
    //         for(int j = 0; j < m; ++j){
    //             if(vet[i][j] == vet[i][(j+1)%m]){
    //                 uf.Union(m*i + j, m*i + (j+1)%m);
    //             }
    //             if(vet[i][j] == vet[(i+1)%n][j]){
    //                 uf.Union(m*i + j, m*((i+1)%n) + j);
    //             }
    //         }
    //     }
    //     ll x, y, res = 0;
    //     cin >> x >> y;
    //     if(vet[x][y] == 'l'){
    //         ll aux = uf.Find(m*x + y);
    //         res = uf.sum[aux] ;
    //     }
    //     cout << res << endl;
    // }
    ll n, m;
    cin >> n >> m;
    UnionFind uf(n+1);
    for(int i = 0; i < m; ++i){
        ll a, b;
        cin >> a >> b;
        uf.Union(a, b);
    }
    ll res = 0;
    for(int i = 1; i <= n; ++i){
        ll aux = uf.Find(i);
        res = max(res, uf.sum[aux]);
    }
    cout << res << endl;

    
    return 0;
}