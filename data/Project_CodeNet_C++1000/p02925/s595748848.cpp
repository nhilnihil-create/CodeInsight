#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define print(x)cout<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main() {
  int n;
  cin >> n;
  vector<vi> a(n,vi(n-1));
  rep(i,n)rep(j,n-1){
    cin >> a[i][j];
    a[i][j]--;
  }
  rep(i,n)reverse(rng(a[i]));
  queue<P> q;
  auto check = [&](int i){
    if(a[i].size() == 0)return;
    int j = a[i].back();
    if(a[j].size() == 0)return;
    if(a[j].back() == i){
      if(i>j)swap(i,j);
      P p(i,j);
      q.push(p);
    }
  };
  rep(i,n){
    check(i);
  }
  int day = 0;
  while(!q.empty()){
    day++;
    queue<P> prevQ;
    swap(q,prevQ);
    int flag[1001][1001];
    while(!prevQ.empty()){
      int i = prevQ.front().fi,j = prevQ.front().se;
      prevQ.pop();
      if(flag[i][j] == 535)continue;
      flag[i][j] = 535;
      a[i].pop_back();
      a[j].pop_back();
      check(i);check(j);
    }
  }
  rep(i,n){
    if(a[i].size() != 0){
      cout<<-1<<endl;
      return 0;
    }
  }
  cout<<day<<endl;
  return 0;
}