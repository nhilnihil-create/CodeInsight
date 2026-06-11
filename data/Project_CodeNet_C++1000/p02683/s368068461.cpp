#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double lld;
ll MOD = (1e9)+7;
const int dr[] = {+1, -1, +0, +0, +1, -1, +1, -1};
const int dc[] = {+0, +0, +1, -1, +1, -1, -1, +1};
const int kx[] = {+1, +2, -1, -2, +1, +2, -1, -2};
const int ky[] = {+2, +1, +2, +1, -2, -1, -2, -1};
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
inline void fastIO(){
  ios_base::sync_with_stdio(0);cin.tie(0);
}
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void debug_out() { cerr << endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << ' ' << H; debug_out(T...); }

#ifdef LOCAL
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", debug_out(__VA_ARGS__)
#else
#define debug(...) 47
#endif

int main(){
  fastIO();
  ll n,m,x,c=10,ans=1e18;
  cin>>n>>m>>x;
  ll books[n+c][m+c];
  vector<ll>prices(n);
  for(int i=0;i<n;i++){
    cin>>prices[i];
    for(int j=0;j<m;j++){
      cin>>books[i][j];
    }
  }
  for(int i=0;i<pow(2,n);i++){
    ll money=0,cnt=0;
    vector<ll>each(m);
    for(int bit=0;bit<n;bit++){
      if(i&(1<<bit)){
        money+=prices[bit];
        for(int j=0;j<m;j++){
          each[j]+=books[bit][j];
        }
      }
    }
    for(int j=0;j<m;j++){
      if(each[j]>=x)cnt++;
    }
    if(cnt==m){
      ans=min(ans,money);
    }
  }
  if(ans==1e18){
    cout<<-1<<endl;
  }else{
    cout<<ans<<endl;
  }
  return 0;
}
