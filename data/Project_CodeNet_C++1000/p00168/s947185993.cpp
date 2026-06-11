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

ll dp[32];
int N;

int main(){
  while(cin >> N, N){
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0;i<N;i++){
      for(int j=1;j<=3;j++){
	dp[i+j] += dp[i];
      }
    }
    int day = dp[N]/10 + ((dp[N]%10)?1:0);
    int res = day/365 + ((day%365)?1:0);
    cout <<  res << endl;
    //    cout << dp[N] << endl;;
  }
  return 0;
}