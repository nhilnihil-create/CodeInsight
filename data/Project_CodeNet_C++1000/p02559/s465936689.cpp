#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
#define vec vector<ll>
#define mat vector<vector<ll> >
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef complex<double> comp;
const ll INF=1e9+7;
const ll MOD=998244353;
const int MAX=200010;

template< class T >
struct BIT
{
  vector< T > data;

  BIT(int sz)
  {
    data.assign(++sz, 0);
  }

  T sum(int k)
  {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x)
  {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    BIT<ll> bit(n);
    ll q;cin>>q;
    rep(i,n){
        ll a;cin>>a;
        bit.add(i,a);
    }
    rep(i,q){
        ll a,b,x;cin>>a>>b>>x;
        if(a==0){
            bit.add(b,x);
        }else{
            ll res=bit.sum(x-1);
            if(b)res-=bit.sum(b-1);
            cout<<res<<endl;
        }
    }
}