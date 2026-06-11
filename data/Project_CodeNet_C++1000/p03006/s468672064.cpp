#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <cstdint>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000
#define MAX 200001

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const ll MOD = 1000000007;

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

int par[100];

void init(int N){
    rep(i,N) par[i] = -1;
}

int find(int a){
    if(par[a] < 0) return a;
    else{
        return par[a] = find(par[a]);
    }
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    else{
        if(par[a] > par[b]) swap(a,b);
        par[a] += par[b];
        par[b] = a;
    }
}

int size(int A) {
     return -par[find(A)];
}

bool same(int a, int b){
    return find(a) == find(b);
}

int main(){
    int N;
    cin >> N;
    int ans = 100;
    vector<int> x(N),y(N);
    rep(i,N) cin >> x[i] >> y[i];
    rep(i,N){
        rep(j,N){
            if(i == j) continue;
            init(N);
            int p = x[i]-x[j];
            int q = y[i]-y[j];
            rep(k,N){
                rep(l,N){
                    if(k == l) continue;
                    if(x[k]-x[l] == p && y[k]-y[l] == q){
                        unite(k,l);
                    }
                }
            }
            set<int> s;
            rep(k,N){
                s.insert(find(k));
            }
            int cnt = s.size();
            ans = min(ans,cnt);
        }
    }
    if(N == 1) ans = 1;
    cout << ans << endl;
}