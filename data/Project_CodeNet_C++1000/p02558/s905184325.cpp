#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

#include <atcoder/all>
using namespace atcoder;

int main(){
    int n,q;
    cin >> n >> q;
    dsu d(n);

    rep(i,q){
        int t,u,v;
        cin >> t >> u >> v;
        if(t==0){
            d.merge(u,v);
        }else{
            cout << (d.same(u,v)?1:0) << endl;
        }
    }
}