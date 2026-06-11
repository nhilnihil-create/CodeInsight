#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORL(i,x) for(int i=head[x];i;i=nxt[i])
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define PB push_back
#define MP make_pair
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main() {
  int N;
  scanf("%d", &N);
  int x[N],y[N];
  for (int i = 0; i < N; ++i) {
    scanf("%d%d", &x[i],&y[i]);
  }

  map<pair<int,int>,int> v;
  int max = 0;

  FOR(i,0,N-1){
    FOR(j,0,N-1){
      if(i==j) continue;
      ++v[MP((x[i]-x[j]),(y[i]-y[j]))];
      chmax(max,v[pair<int,int>((x[i]-x[j]),(y[i]-y[j]))]);
    }
  }

  cout << N - max << endl;



}

