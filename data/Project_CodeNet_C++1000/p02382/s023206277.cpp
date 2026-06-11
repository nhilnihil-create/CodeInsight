#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>
#include<numeric>
using namespace std;


int main(void) {

  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for(int i=0; i<n; i++) cin >> x[i];
  for(int i=0; i<n; i++) cin >> y[i];

  vector<double> ans(4, 0);

  for(int i=0; i<n; i++){
    ans[0] += abs(x[i]-y[i]);
  }

  for(int i=0; i<n; i++){
    ans[1] += (x[i]-y[i])*(x[i]-y[i]);
  }
  ans[1] = sqrt(ans[1]);

  for(int i=0; i<n; i++){
    ans[2] += abs((x[i]-y[i])*(x[i]-y[i])*(x[i]-y[i]));
  }
  ans[2] = cbrt(ans[2]);

  for(int i=0; i<n; i++){
    ans[3] = max(ans[3], (double)abs(x[i]-y[i]) );
  }

  for(int i=0; i<4; i++) printf("%.8lf\n",ans[i]);

  return 0;
}