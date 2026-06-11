#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>


#define REP(i,n) for (int i = 0; (i) < (n); ++ (i))
#define FOR(i,n) for (int i = 1; (i) <= (n); ++ (i))
#define dump(x)  cout << #x << " = " << (x) << endl;
#define pb push_back
#define int long long
//#define lint long long

const int INF = 1e18;
const int MOD = 1e9+7;
//const lint LINF = 1e18;
const double eps = 0.000000001;//もとの値の10^(-16)まで

using namespace std;

//typedef pair<int, int> P;
//priority_queue< P, vector<P>, greater<P> > q;//ダイクストラの時、greaterで小さい順
vector<int> v;
vector<int> v2;

signed main(){
  int n;
  cin >>n;
  REP(i,pow(2,n)){
    int k;
    cin >> k;
    v.pb(-k);
  }
  v.pb(INF);
  sort(v.begin(),v.end());
  v2.pb(v[0]);
  v[0]=-INF;
  REP(i,n){
    sort(v.begin(),v.end());
    sort(v2.begin(),v2.end());
    REP(j,pow(2,i)){
      int k2 = v2[j];
      int t2 = lower_bound(v.begin(),v.end(),k2+1)-v.begin();
      if(v[t2]==INF){
        cout << "No" << endl;
        return 0;
      }
      v2.pb(v[t2]);
      v[t2]=-INF;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
