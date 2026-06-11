#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef pair<double,double> P;
typedef pair<double,P> PP;

vector<PP> d;

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    double x,y;
    cin >> x >> y;
    d.push_back(PP(atan2(y,x),P(x,y)));
  }

  sort(d.begin(),d.end());


  long double ans = 0;

  for(int i = 0; i < n; i++) {
    long double x = 0;
    long double y = 0;
    for(int j = 0; j < n; j++) {
      x += d[(i+j) % n].second.first;
      y += d[(i+j) % n].second.second;
      ans = max(ans,sqrt(x*x+y*y));
    }
  }

  cout << setprecision(20) << ans << endl;
  

 
}
	
