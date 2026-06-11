#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,n,x); REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

#define umap unordered_map
//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }



int main(){
  int N; cin>>N;
  vector<int> nexts[N+1];
  pair<int,int> edge[N];
  int use[N+1]; FILL(use,N+1,0);
  REP(i,N-1){
      int a,b;
      scanf("%d %d",&a,&b);
      nexts[a].push_back(b);
      nexts[b].push_back(a);
      edge[i] = make_pair(a,b);
  }
  
  int color_p[N+1]; FILL(color_p,N+1,0);
  FILL(color_p,N+1,0);
  map< pair<int,int> , int> mp;
  queue<int> q;
  q.push(1);
  use[1] = 1;
  int s = 0;
  while(!q.empty()){
      int base = q.front(); q.pop();
      chmax(s, (int)nexts[base].size() );
      int cur = 1;
      for(int next: nexts[base]){
          if( use[next] ){ continue;}
          if(color_p[base]==cur){ ++cur; }
          color_p[next] = cur;
          mp[ make_pair(base,next) ] = cur;
          mp[ make_pair(next,base) ] = cur;
          ++cur;
          use[next] = 1;
          q.push(next);
      }
  }
  
  cout << s <<"\n";
  REP(i,N-1){
      printf("%d\n",mp[edge[i]]);
  }
}