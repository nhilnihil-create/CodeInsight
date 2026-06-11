#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
  double N, D;
  cin >> N >> D;
  vector<double> X(N), Y(N);
  vector<double> dist(N);
  int ans = 0;
  for(int i=0; i<N; i++){
    cin >> X.at(i) >> Y.at(i);
    dist.at(i) = pow(X.at(i)*X.at(i)+Y.at(i)*Y.at(i),0.5);
    if(dist.at(i)<=D){
      ans++;
    }
  }
  cout << ans;
  return 0;
}