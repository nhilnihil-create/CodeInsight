#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double lld;
ll MOD = 998244353;
ll inf=1e17;
const int dr[] = {+1, -1, +0, +0, +1, -1, +1, -1};
const int dc[] = {+0, +0, +1, -1, +1, -1, -1, +1};
const int kx[] = {+1, +2, -1, -2, +1, +2, -1, -2};
const int ky[] = {+2, +1, +2, +1, -2, -1, -2, -1};
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
  ll n,k,start,beg,len=0,pos=0,pre=1;
  bool cycle=false;
  cin>>n>>k;
  ll tempK=k;
  vector<ll>a(n);
  map<ll,ll>rep;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  while(rep[pos]==0&&k>0){
    rep[pos]++;
    pos=a[pos]-1,start=pos;
    beg=pos,k--;
  }
  k=tempK;
  if(rep[pos]==1)cycle=true;
  if(cycle){
    pre=rep.size();
    rep.clear();
    while(rep[start]==0){
      rep[start]++;
      start=a[start]-1,len++;
    }
    pre-=len;
    ll modded=(k-pre+len)%len;
    for(int i=0;i<modded;i++){
      beg=a[beg]-1;
    }
  }
  cout<<beg+1<<endl;
  return 0;
}
