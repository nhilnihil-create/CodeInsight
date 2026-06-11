#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vs = vector<string>;
using vb = vector<bool>;
using vll = vector<long long>;
using vpii = vector<pair<int,int>>;
using vivi = vector<vector<int>>;
using vbvb = vector<vector<bool>>;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int mod = 1000000007;
const int inf = 1001001001;



int main(void) {
  ll n,m,v,p;
  cin >> n >> m >> v >> p;
  vll a(n);
  rep(i,n) cin >> a[i];
  sort(ALL(a));
  vll s(n+1);
  s[0] = 0;
  rep(i,n) s[i+1] = s[i]+a[i];
  ll cnt = 0;
  rep(i,n){
    if(a[i]+m<a[n-p])continue;
    ll vorte = m*(v);
    ll l = upper_bound(ALL(a),a[i])-a.begin();
    //ll u = lower_bound(ALL(a),a[i])-a.begin();
    ll r = lower_bound(ALL(a),a[i]+m)-a.begin();
    //ll k = distance(upper_bound(ALL(a),a[i]+m),a.end());
    vorte -= m*l;
    //if(i==2)cout << k << endl;
    vorte -= m*(p-1);
    vorte -= max((a[i]+m)*(min(r-1,n-p)-l+1)-s[min(r,n-p+1)]+s[l],0LL);
    //if(i==2)cout << s[r] << " " << s[l]  << endl;
    if(vorte<=0LL){
      cnt++;
      //cout << i << endl;
    }
  }
  cout << cnt << endl;
  
}




