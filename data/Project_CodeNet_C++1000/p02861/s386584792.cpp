#include<bits/stdc++.h>
using namespace std;
  
int main(){
  int N;
  cin >> N;
  double A=0;
  vector<int> X(N),Y(N);
  for(int i=0;i<N;i++){
    cin >> X.at(i) >> Y.at(i);
  }
  for(int i=0;i<N-1;i++){
    for(int j=i+1;j<N;j++){
      int X1=X.at(i)-X.at(j);
      int Y1=Y.at(i)-Y.at(j);
      A+=sqrt(X1*X1+Y1*Y1);
    }
  }
  double ans=2*A/N;
  cout << fixed << setprecision(10) << ans << endl;
}