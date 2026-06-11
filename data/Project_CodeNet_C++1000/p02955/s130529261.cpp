#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

const int MAX = 510000;
const int MOD = 1000000007;

// 約数の列挙
vector<ll> divisor(ll n) {
    vector<ll> res;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) {
                res.push_back(n / i);
            }
        }
    }
    return res;
}

int main(){
  ll N,K;cin>>N>>K;
  vector<ll> v(N);
  rep(i,N) cin>>v[i];

  ll sum = 0;
  rep(i,N) sum+= v[i];

  //約数vectorを作成
  vector<ll> a;
  a = divisor(sum);
  a.pb(1); a.pb(sum);
  SORT(a);

  ll d = a.size();
  for(ll i = d-1; i >= 0; i--){
    vector<ll> cnt(N);
    ll re=0;
    rep(j,N){
      cnt[j] = v[j]%a[i];
      re += cnt[j];
    }

    SORT(cnt);
    //cはそこからひく場所
    ll c = re/a[i];
    ll check = 0;
    rep(j,N-c){
      check += cnt[j];
    }
    if(check<=K){
      cout<<a[i]<<endl;
      return 0;
    }
  }

}
