#include <bits/stdc++.h>
//#include <chrono>
//#pragma GCC optimize("Ofast")
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,Q,K,A,B;
string S;
typedef pair<ll, ll> P;
const ll INF = (1LL<<60);


int main() {
    class BIT{
            ll n;
      		vector<ll> bitree;
        public:
        	BIT(unsigned long _n) : bitree(_n + 1, 0){
              n = _n;
            }
        	void add(ll id, ll x){
              while(id <= n){
                bitree[id] += x;
                id += id & -id;
              }
              return;
            }
        	ll sum(ll id){
              ll temp = 0;
              while(id > 0){
                temp += bitree[id];
                id -= id & -id;
              }
              return temp;
            }
      };
    cin>>N>>Q;
    BIT bit(N);
    rep(i, N){
        scanf("%lld", &A);
        bit.add(i + 1, A);
    }
    rep(i, Q){
        int t, u, v;
        scanf("%d%d%d", &t, &u, &v);
        if(t == 0){
            bit.add(u + 1, v);
        }else{
            printf("%lld\n", bit.sum(v) - bit.sum(u));
        }
    }
}
