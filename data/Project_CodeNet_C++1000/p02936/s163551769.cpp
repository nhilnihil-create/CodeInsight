#include <algorithm>
#include <iostream> //標準入出力
#include <fstream>  //ファイルでの入出力
#include <vector>
#include <set>
#include <functional>
#include <string>
#include <utility> //pair
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define MAX 1000000
#define pair(a) pair<a,a>

vector<ll> counter;
vector<bool> seen;
void dfs(vector<vector<ll>>& graph,vector<ll>& xs,ll& p){
    counter[p] = xs[p];
    seen[p]=true;
    for(auto son: graph[p]){
        if(seen[son]) continue;
        xs[son] += xs[p];
        if(graph[son].size()>0){
            dfs(graph,xs,son);
        }
        else counter[son] = xs[son];
    }
    return;
}

void _main(){
    ll n,q;cin >> n >> q;
    vector<vector<ll>> graph(n);
    vector<ll> xs(n,0);
    counter.resize(n);
    seen.resize(n);
    rep(i,n){
        counter[i]=0;
        seen[i]=false;
    }
    rep(i,n-1){
        ll a,b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    rep(i,q){
        ll p,x; cin >> p >> x;
        xs[p-1] += x;
    }
    ll zero = 0;
    dfs(graph,xs,zero);
    rep(i,n){
        cout << counter[i] << ' ';
    }
    cout << endl;
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
    