#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n, k;
  cin >> n >> k;
  vector<double> vec(n);
  vector<double> ta(n+1);
  rep(i,n){
    double pi;
    cin >> pi;
    vec.at(i) = (pi + 1) / 2;
  }
  double sum = 0;
  rep(i,n){
    ta.at(i+1) = ta.at(i) + vec.at(i);
  }
  double ans = 0;
  double index;
  REP(i,k,n+1){
    index = ta.at(i) - ta.at(i-k);
    ans = max(ans, index);
    /*cout << ans << endl;
    cout << endl;*/
  }
  printf("%.10f", ans);
  return 0;
}
