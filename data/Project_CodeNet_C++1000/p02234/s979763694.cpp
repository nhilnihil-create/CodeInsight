#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

//const ll INF=(ll)1e19;
const int INF=(1<<30);

vector<int> r;
vector<int> c;
int dp[105][105];


int main(){
  int n;
  cin >> n;
  REP(i,n){
    int rr,cc;
    cin >> rr >> cc;
    r.emplace_back(rr);
    c.emplace_back(cc);
  }

  REP(i,n)REP(j,n)dp[i][j]=INF;

  REP(i,n)REP(j,n){
    if(j+i >=n)continue;
    if(i==0){
      dp[j][j] = 0;
    }else{

      FOR(k,j,j+i){
        chmin(dp[j][j+i], dp[j][k] + r[j]*c[k]*c[j+i] + dp[k+1][j+i]);
      }
    }
  }

  cout << dp[0][n-1] << endl;
}

