#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<algorithm> // sort
#include<map> // pair
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<set>
#include<queue>
// #include<stack>
using namespace std;
typedef long long ll;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define rep(i, n) REP(i, 0, n)
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define all(x) (x).begin(),(x).end()
ll tmp1,tmp2;
const ll mod = 1e9+7;
const int INF = 1e9;
const ll INFLONG = 1e18;
//vector<vector<ll>> vec(1000,vector<ll>(1000));
vector<pair<double, double>> vec1(100);
int main(){
  ll n;
  cin >> n;
  vector<pair<double,double>> radi(n);
  double ans = 0.0;
  rep(i,n){
    cin >> tmp1 >> tmp2;
    vec1[i] = make_pair(tmp1,tmp2);
    radi[i] = make_pair(atan2(tmp1,tmp2),i);
  }
  sort(all(radi));
  double tmpx,tmpy;
  rep(i,n){//size
    rep(j,n){//start
      tmpx = 0.0;tmpy=0.0;
      REP(k,j,j+i+1){
        tmpx += vec1[radi[k%n].second].first;
        tmpy += vec1[radi[k%n].second].second;
      }
      //cout << tmpx << " " << tmpy << endl;
      double tmp = sqrt((double)(tmpx*tmpx+tmpy*tmpy));
      // if(tmp > 18){
      //   cout << tmp << " " << i << " " << j << " " << endl;
      // }
      chmax(ans,tmp);
    }
  }
  printf("%.20lf",ans);
}
