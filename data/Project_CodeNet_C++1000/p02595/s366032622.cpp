#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(void){
  long long N,D;
  cin >> N >> D;
  
  vector<vector<long long>>p(N,vector<long long>(2));
  
  for(int i=0;i<N;i++){
    cin >> p[i][0] >> p[i][1];
  }
  
  int ans = 0;
  
  for(int i=0;i<N;i++){
    double distance = sqrt(p[i][0] * p[i][0] + p[i][1] * p[i][1]);
    if(distance <= D) ans++;
  }

  cout << ans << endl;
  
  return 0;
}
