#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>>XY(2, vector<int>(N));
  for(int i=0; i<N; i++)cin >> XY.at(0).at(i) >> XY.at(1).at(i);
  
  //int kaijou=1;
  //for(int i=1; i<=N; i++)kaijou *=i;
  
  int kyori=0;
  double wa =0;
  
  for(int i=0; i<N; i++){
    for(int j=i+1; j<N; j++){
      kyori = (XY.at(0).at(i)-XY.at(0).at(j))*(XY.at(0).at(i)-XY.at(0).at(j)) + (XY.at(1).at(i)-XY.at(1).at(j))*(XY.at(1).at(i)-XY.at(1).at(j));
      wa += sqrtl(kyori);
    }
  }
  
  wa = wa*2/N;
  
  cout <<std::setprecision(8) << wa<< endl;
}