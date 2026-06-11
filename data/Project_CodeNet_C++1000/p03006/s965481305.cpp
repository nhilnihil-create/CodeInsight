#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v1;
typedef vector<vector<ll>> graph;

const ll INF = 1ll << 50;
const ll mod = 1000000007;

class union_find {
private:
  v1 *par;
  v1 *rnk;
  v1 *siz;
public:
  union_find (ll n){
    par = new v1(n);
    iota(par->begin(),par->end(),0);
    rnk = new v1(n,0);
    siz = new v1(n,1);
  }
  ll find(ll x){
    if(par->at(x) == x) return x;
    else return par->at(x) = find(par->at(x));
  }
  ll size(ll x){
    return siz->at(find(x));
  }
  void unite(ll x,ll y){
    x = find(x);y = find(y);
    if(x == y)return;
    if(rnk->at(x) < rnk->at(y)){
      par->at(x) = y;
      siz->at(y) += siz->at(x);
    }
    else {
      par->at(y) = x;
      siz->at(x) += siz->at(y);
      if(rnk->at(x) == rnk->at(y)) rnk->at(x)++;
    }
  }
  bool same(ll x,ll y){
    return find(x) == find(y);
  }
};

ll n;
ll x[100000];
ll y[100000];
ll ans = INF;

int main(){
    cin >> n;
    for(ll i = 0;i < n;i++){
        cin >> x[i] >> y[i];
    }
    for(ll i = 0;i < n;i++){
        for(ll j = 0;j < n;j++){
            ll p = x[i] - x[j];
            ll q = y[i] - y[j];
            union_find uf(n);
            for(ll k = 0;k < n;k++){
                for(ll l = 0;l < n;l++){
                    if(x[k]-x[l] == p && y[k]-y[l] == q){
                        uf.unite(k,l);
                    }
                }
            }
            set<ll> s;
            for(ll k = 0;k < n;k++){
                s.insert(uf.find(k));
            }
            ans = min(ans,(ll)s.size());
        }
    }
    cout << ans << endl;
}
