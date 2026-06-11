#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define BW(a,x,b) ((a)<=(x)&&(x)<=(b))
#define ALL(v) (v).begin(), (v).end()
#define LENGTHOF(x) (sizeof(x) / sizeof(*(x)))
#define AFILL(a, b) fill((int*)a, (int*)(a + LENGTHOF(a)), b)
#define SQ(x) ((x)*(x))
#define Mod(x, mod) (((x)+(mod)%(mod))
#define MP make_pair
#define PB push_back
#define Fi first
#define Se second
#define INF (1<<29)
#define EPS 1e-10
#define MOD 1000000007

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;

int N,M;
vector<int>v1,v2;
vector<int>h(N),w(M);

int main(){
  while(cin >> N >> M && N && M){
    v1.clear();
    v2.clear();
    h.resize(N+1);
    w.resize(M+1);
    rep(i,N) cin >> h[i+1];
    rep(i,M) cin >> w[i+1];
    
    rep(i,N) h[i+1] += h[i];
    rep(i,M) w[i+1] += w[i];
  
    for(int i=0;i<=N;i++){
      for(int j=i+1;j<=N;j++){
	v1.push_back(h[j]-h[i]);
      }
    }

    for(int i=0;i<=M;i++){
      for(int j=i+1;j<=M;j++){
	v2.push_back(w[j]-w[i]);
      }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
  
    int res = 0;
    rep(i,v1.size()){
      vector<int>::iterator it = lower_bound(v2.begin(), v2.end(), v1[i]);
      while(it != v2.end() && *it == v1[i]){
	res++;
	it++;
      }
    }

    cout << res << endl;
  }
  return 0;
}