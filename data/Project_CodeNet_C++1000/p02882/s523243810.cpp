#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  double a,b,x; cin >> a >> b >> x;
  double s = x/a;
  if(s < a*b/2){
    double w = 2*s/b;
    cout << setprecision(10) << atan2(b,w)/(2*M_PI)*360.0;
  }else{
    double h = 2*(a*b-s)/a;
    cout << setprecision(10) << atan2(h,a)/(2*M_PI)*360.0;
  }
  cout << "\n";
  return 0;
}
