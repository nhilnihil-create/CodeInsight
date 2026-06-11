#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
//#define ll long long
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define rep(i, n) REP(i, 0, n)
#define rep_rev(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define all(x) (x).begin(),(x).end()
ll t1,t2,t3;
const ll mod = 998244353;
const int INF = 1e9;
const ll INFLONG = 1e18;


int main(){
  ll n;
  cin >> n;
  ll mini;
  ll maxi;
  bool minhasu = false;
  bool maxhasu = false;
  vector<pair<ll,ll>> vec1(n);
  vector<pair<ll,ll>> vec2(n);

  rep(i,n){
    cin >> t1 >> t2;
    vec1[i].first = t1;
    vec1[i].second = t2;
    vec2[i].first= t2;
    vec2[i].second = t1;

  }
  ll ans;
  sort(all(vec1));
  sort(all(vec2));
  if(n % 2 == 0){
    t1 = vec1[n/2-1].first + vec1[n/2].first;
    t2 = vec2[n/2-1].first + vec2[n/2].first;

//    mini = t1 / 2;
//    maxi = t2 / 2;
//    if(t1 % 2 == 1){
//      minhasu = true;
//    }
//    if(t2 % 2 == 1){
//      maxhasu = true;
//    }
    t3 = t2 - t1;
    ans = t3+1;
  }else{
    mini = vec1[n/2].first;
    maxi = vec2[n/2].first;

    ans = maxi - mini + 1;
  }
  cout << ans << endl;
}