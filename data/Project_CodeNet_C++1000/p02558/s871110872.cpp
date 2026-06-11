#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
#define mp make_pair
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<int>>;
#define MAX 1000000007
#include<atcoder/all>
using namespace atcoder;

int main()
{
    int n,q;
    cin >> n >> q;
    vector<int> t(q),u(q),v(q);
    rep(i,q)cin >> t[i] >> u[i] >> v[i];

    dsu d(n);
    rep(i,q){
        if(t[i]==1){
            if(d.same(u[i],v[i])){
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
        }else{
            d.merge(u[i],v[i]);
        }
    }

}