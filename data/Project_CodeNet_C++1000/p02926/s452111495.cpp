#include <bits/stdc++.h>
// atoi : atoi(str.c_str())
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
#define fix10 cout << fixed << setprecision(20);
#define rep(i,n) for(int i=0; i<(int)(n);i++)

int main(){
  fix10;
  double PI = acos(-1);
  int n;
  cin >> n;
  vector<tuple<double,long,long>> engine(n);
  rep(i,n){
    long x,y;
    cin >> x >> y;
    engine.at(i) = make_tuple(atan2(y,x),x,y);
  }
  sort(engine.begin(),engine.end());
  
  double maxi = 0;
  rep(i,n){
    double shita = get<0>(engine.at(i));
    long X = 0;
    long Y = 0;
    int count = 0;
    for(int j = i; count < n ; j = (j+1)%n){
      if(get<0>(engine.at(j)) >= shita + PI) break;
      X += get<1>(engine.at(j));
      Y += get<2>(engine.at(j));
      count++;
      double dis0 = sqrt(X*X+Y*Y);
      maxi = max(maxi,dis0);
    }
    double dis = sqrt(X*X+Y*Y);
    maxi = max(maxi,dis);
    get<0>(engine.at(i)) = shita + 2*PI;
  }
  cout << maxi << endl;
}
